/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:30:30 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/18 19:12:59 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

enum	e_player_direction{
	NORTH = 0,
	NE = 1,
	EAST = 2,
	SE = 3,
	SOUTH = 4,
	SW = 5,
	WEST = 6,
	NW = 7
};

int	determine_direction(t_point *dir)
{
	if (dir->x == 0)
	{
		if (dir->y > 0)
			return (SOUTH);
		return (NORTH);
	}
	if (dir->y == 0)
	{
		if (dir->x > 0)
			return (EAST);
		return (WEST);
	}
	if (dir->x > 0)
	{
		if (dir->y > 0)
			return (SE);
		return (NE);
	}
	if (dir->x < 0)
	{
		if (dir->y > 0)
			return (SW);
		return (NW);
	}
	return (-1);
};


float	calculate_delta(float  position_x, float norm_dir_x)
{
	float	x_factor;

	if (norm_dir_x > 0)
		x_factor = ( (float)((int)(position_x) + 1) - position_x) / norm_dir_x;
	else
	{
		if (((float)((int)position_x) - position_x) == 0)
			x_factor = - 1 / norm_dir_x;
		else
			x_factor = ((float)((int)position_x) - position_x) / norm_dir_x;
	}
	return (x_factor);
}


t_point	first_axis_collision(t_point position, t_point norm_dir, float x_factor)
{
	t_point	result;

	result.x = 0;
	result.y = 0;
	result.x = position.x + norm_dir.x * x_factor;
	result.y = position.y + norm_dir.y * x_factor;
	return (result);
}

t_point	get_first_collision_dda(t_cub3d *game, t_point norm_dir)
{
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX; // fabs(1 / norm_dir.x)
	double	deltaDistY; // fabs(1 / norm_dir.y)
	// double	wallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		hit_x;
	int		hit_y;
	// int		side;
	t_point	map;

	t_point	x_vector;
	t_point	y_vector;
	t_point	diffs[2];
	
	deltaDistX = calculate_delta(game->player.pos.x, norm_dir.x);
	deltaDistY = calculate_delta(game->player.pos.y, norm_dir.y);
	if (norm_dir.x != 0)
		x_vector = first_axis_collision(game->player.pos, norm_dir, deltaDistX);
	else
	{
		x_vector.x = 0;
		x_vector.y = 0;
	}
	if (norm_dir.y != 0)
		y_vector = first_axis_collision(game->player.pos, norm_dir, deltaDistY);
	else
	{
		y_vector.x = 0;
		y_vector.y = 0;
	}
	
	hit_x = 0;
	hit_y = 0;
	if (square_dir_check(game, &x_vector, &norm_dir) == '1')
		hit_x = 1;
	if (square_dir_check(game, &y_vector, &norm_dir) == '1')
		hit_y = 1;
	if (hit_x == 1 && hit_y == 1)
	{
		diffs[0] = subtract_vector(&x_vector, &game->player.pos);
		diffs[1] = subtract_vector(&y_vector, &game->player.pos);
		if (diffs[0].x*diffs[0].x + diffs[0].y*diffs[0].y > diffs[1].x*diffs[1].x + diffs[1].y*diffs[1].y)
			return (y_vector);
		return (x_vector);
	}
	else if (hit_x == 1 && hit_y == 0)
		return (x_vector);
	else if (hit_y == 1 && hit_x == 0)
		return (y_vector);

	deltaDistX = 1000;
	deltaDistY = 1000;
	if (norm_dir.x != 0)
		deltaDistX = calculate_delta(x_vector.x, norm_dir.x);
	if (norm_dir.y != 0)
		deltaDistY = calculate_delta(y_vector.y, norm_dir.y);
	
	map.x = (int)game->player.pos.x;
	map.y = (int)game->player.pos.y;
	
	// calculate step and initial sideDist
	if (norm_dir.x < 0)
	{
		stepX = -1;
		sideDistX = (game->player.pos.x - map.x) * deltaDistX;
	}
	else
	{
		stepX = 1;
		sideDistX = (map.x + 1.0 - game->player.pos.x) * deltaDistX;
	}
	if (norm_dir.y < 0)
	{
		stepY = -1;
		sideDistY = (game->player.pos.y - map.y) * deltaDistY;
	}
	else
	{
		stepY = 1;
		sideDistY = (map.y + 1.0 - game->player.pos.y) * deltaDistY;
	}

	//perform DDA
	hit = 0;
	while (hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			map.x += stepX;
			// side = 0;
		}
		else
		{
			sideDistY += deltaDistY;
			map.y += stepY;
			// side = 1;
		}
		//Check if ray has hit a wall
		printf("Map.x: %f\nMap.y: %f", map.x, map.y);
		if (square_dir_check(game, &map, &norm_dir) == '1')
			hit = 1;
	}
	return (map);
}