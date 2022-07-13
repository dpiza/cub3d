/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_collision_util.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:30:30 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/12 21:15:30 by hde-camp         ###   ########.fr       */
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

t_point	get_first_collision(t_cub3d	*game, t_point	norm_dir)
{
	t_point	*x_vectors;
	t_point	*y_vectors;
	t_point	first_x_wall;
	t_point	first_y_wall;
	t_point	diffs[2];
	int		count;

	x_vectors = ft_calloc(game->map->columns ,sizeof(t_point));
	y_vectors = ft_calloc(game->map->lines ,sizeof(t_point));
	y_vectors[0] = first_axis_collision_y(game->player.pos, norm_dir);
	count = 1;
	
	x_vectors[0] = first_axis_collision_x(game->player.pos, norm_dir);
	//if (square_check(game, x_vectors[0].x, x_vectors[0].y) != '1')
	if (square_dir_check(game, &x_vectors[0], &norm_dir) != '1')
	{
		count = 1;
		first_x_wall = x_vectors[0];
		while (count < game->map->columns -1)
		{
			x_vectors[count] = first_axis_collision_x(x_vectors[count - 1], norm_dir);
			if (x_vectors[count].x < 0 || x_vectors[count].y < 0)
				break;
			if (square_dir_check(game, &x_vectors[count], &norm_dir) == '1')
			{
				first_x_wall = x_vectors[count];
				break;
			}
			count++;
		}
	}
	else
		first_x_wall = x_vectors[0];
	if (square_dir_check(game, &y_vectors[0], &norm_dir) != '1')
	{
		count = 1;
		first_y_wall = y_vectors[0];
		while (count < game->map->lines -1)
		{
			y_vectors[count] = first_axis_collision_y(y_vectors[count - 1], norm_dir);
			if (y_vectors[count].x < 0 || y_vectors[count].y < 0)
				break;
			if (square_dir_check(game, &y_vectors[count], &norm_dir) == '1')
			{
				first_y_wall = y_vectors[count];
				break;
			}
			count++;
		}
	}
	else
		first_y_wall = y_vectors[0];
	free(x_vectors);
	free(y_vectors);
	
	diffs[0] = subtract_vector(&first_x_wall, &game->player.pos);
	diffs[1] = subtract_vector(&first_y_wall, &game->player.pos);
	if (vector_size(&diffs[0]) > vector_size(&diffs[1]))
		return (first_y_wall);
	return (first_x_wall);
}

t_point	first_axis_collision_x(t_point  position, t_point	norm_dir)
{
	float	x_factor;
	t_point	result;

	result.x = 0;
	result.y = 0;
	if (norm_dir.x == 0)
		return (result);
	if (norm_dir.x > 0)
		x_factor = ( (float)((int)(position.x) + 1) - position.x) / norm_dir.x;
	else
	{
		if ( ((float)((int)position.x) - position.x) == 0)
			x_factor = - 1 / norm_dir.x;
		else
			x_factor = ((float)((int)position.x) - position.x) / norm_dir.x;
	}
	result.x = position.x + norm_dir.x * x_factor;
	result.y = position.y + norm_dir.y * x_factor;
	return (result);
}

t_point	first_axis_collision_y(t_point  position, t_point	norm_dir)
{
	float	x_factor;
	t_point	result;

	result.x = 0;
	result.y = 0;
	if (norm_dir.y == 0)
		return (result);
	if (norm_dir.y > 0)
		x_factor = ( (float)((int)(position.y) + 1) - position.y) / norm_dir.y;
	else
	{
		if (((float)((int)position.y) - position.y) == 0)
			x_factor = - 1 / norm_dir.y;
		else
			x_factor = ((float)((int)position.y) - position.y) / norm_dir.y;
	}
	result.x = position.x + norm_dir.x * x_factor;
	result.y = position.y + norm_dir.y * x_factor;
	return (result);
}