/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:30:30 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/19 12:50:13 by dpiza            ###   ########.fr       */
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

t_point	axis_collision(t_point position, t_point norm_dir, float x_factor)
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
	float	sideDistX;
	float	sideDistY;
	float	deltaDistX;
	float	deltaDistY;
	int		hit;
	t_point	collision;
	float	wallDist;
	int		side;
	
	deltaDistX = 1000;
	deltaDistY = 1000;
	if (norm_dir.x != 0)
		deltaDistX = fabs(1 / norm_dir.x);
	if (norm_dir.y != 0)
		deltaDistY = fabs(1 / norm_dir.y);
	
	// calculate step and initial sideDist
	if (norm_dir.x < 0)
		sideDistX = (game->player.pos.x - (int)game->player.pos.x) * deltaDistX;
	else
		sideDistX = ((int)game->player.pos.x + 1.0 - game->player.pos.x) * deltaDistX;
	if (norm_dir.y < 0)
		sideDistY = (game->player.pos.y - (int)game->player.pos.y) * deltaDistY;
	else
		sideDistY = ((int)game->player.pos.y + 1.0 - game->player.pos.y) * deltaDistY;

	//perform DDA
	hit = 0;
	while (hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (sideDistX < sideDistY)
		{
			collision = axis_collision(game->player.pos, norm_dir, sideDistX);
			wallDist = sideDistX;
			sideDistX += deltaDistX;
			side = 1;
		}
		else
		{
			collision = axis_collision(game->player.pos, norm_dir, sideDistY);
			wallDist = sideDistY;
			sideDistY += deltaDistY;
			side = 0;
		}
		//Check if ray has hit a wall
		if (square_dir_check(game, &collision, &norm_dir) == '1')
			hit = 1;
	}
	// printf("Collision.x: %.2f\nCollision.y: %.2f\n", collision.x, collision.y);
	printf("Side hit: %i\n", side);
	printf("Wall Distance: %.4f\n", wallDist);
	return (collision);
}