/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:30:30 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/27 20:17:26 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_point	axis_collision(t_point position, t_point norm_dir, float x_factor)
{
	t_point	result;

	result.x = 0;
	result.y = 0;
	result.x = roundf((position.x + norm_dir.x * x_factor) * 10000) / 10000;
	result.y = roundf((position.y + norm_dir.y * x_factor) * 10000) / 10000;
	return (result);
}

t_collision	ret_collision_result(t_cub3d *game, t_point *norm_dir, int side, float wall_dist)
{
	t_collision	collision;

	collision.point = axis_collision(game->player.pos, *norm_dir, wall_dist);
	collision.distance = wall_dist;
	collision.perpDistance = wall_dist * (norm_dir->x * game->player.dir.x + norm_dir->y * game->player.dir.y);
	if (side == 1)
	{
		if (norm_dir->x > 0)
			collision.side = WEST;
		else
			collision.side = EAST;
	}
	else
	{
		if (norm_dir->y > 0)
			collision.side = NORTH;
		else
			collision.side = SOUTH;
	}
	return (collision);
}

t_collision	get_collision(t_cub3d *game, t_point norm_dir)
{
	t_point		s_dist;
	t_point		delta;
	t_collision	collision;
	int			xy_steps[2];
	int			map_xy[2];
	float		wall_dist;
	int			side;

	// Initialize default values;
	delta.x = __FLT_MAX__;
	delta.y = __FLT_MAX__;
	s_dist.x = 0;
	s_dist.y = 0;
	if (norm_dir.x != 0)
		delta.x = fabs(1 / norm_dir.x);
	if (norm_dir.y != 0)
		delta.y = fabs(1 / norm_dir.y);
	//define steps
	xy_steps[0] = 1;
	xy_steps[1] = 1;
	if (norm_dir.x < 0)
		xy_steps[0] = -1;
	if (norm_dir.y < 0)
		xy_steps[1] = -1;
	map_xy[0] = (int)game->player.pos.x;
	map_xy[1] = (int)game->player.pos.y;
	// calculate step and initial sideDist
	if (norm_dir.x < 0)
		s_dist.x = (game->player.pos.x - (int)game->player.pos.x) * delta.x;
	else
		s_dist.x = ((int)game->player.pos.x + 1.0 - game->player.pos.x) * delta.x;
	if (norm_dir.y < 0)
		s_dist.y = (game->player.pos.y - (int)game->player.pos.y) * delta.y;
	else
		s_dist.y = ((int)game->player.pos.y + 1.0 - game->player.pos.y) * delta.y;

	////perform DDA
	collision.side = NA;
	while (collision.side == NA)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (s_dist.x < s_dist.y)
		{
			wall_dist = s_dist.x;
			s_dist.x += delta.x;
			map_xy[0] += xy_steps[0];
			side = 1;
		}
		else
		{
			wall_dist = s_dist.y;
			s_dist.y += delta.y;
			map_xy[1] += xy_steps[1];
			side = 0;
		}
		//Check if ray has hit a wall
		if (square_check(game, (float)map_xy[0], (float)map_xy[1]) == '1')
		{
			collision = ret_collision_result(game, &norm_dir, side, wall_dist);
		}
	}
	return (collision);
}
