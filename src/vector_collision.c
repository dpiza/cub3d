/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:30:30 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/28 12:43:38 by dpiza            ###   ########.fr       */
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

t_collision	ret_collision_result(t_cub3d *game, t_point *norm_dir, t_dda dda)
{
	t_collision	collision;

	collision.point = axis_collision(game->player.pos, *norm_dir, dda.w_dist);
	collision.distance = dda.w_dist;
	collision.perpDistance = dda.w_dist * \
		(norm_dir->x * game->player.dir.x + norm_dir->y * game->player.dir.y);
	if (dda.side == 1)
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

t_point	get_delta(t_point norm_dir)
{
	t_point		delta;

	delta.x = __FLT_MAX__;
	delta.y = __FLT_MAX__;
	if (norm_dir.x != 0)
		delta.x = fabs(1 / norm_dir.x);
	if (norm_dir.y != 0)
		delta.y = fabs(1 / norm_dir.y);
	return (delta);
}

t_point	calculate_side_distance(t_cub3d *game, t_point norm_dir, t_point delta)
{
	t_point		s_dist;

	s_dist.x = 0;
	s_dist.y = 0;
	if (norm_dir.x < 0)
		s_dist.x = (game->player.pos.x - (int)game->player.pos.x) * delta.x;
	else
		s_dist.x = ((int)game->player.pos.x + 1 - game->player.pos.x) * delta.x;
	if (norm_dir.y < 0)
		s_dist.y = (game->player.pos.y - (int)game->player.pos.y) * delta.y;
	else
		s_dist.y = ((int)game->player.pos.y + 1 - game->player.pos.y) * delta.y;
	return (s_dist);
}

t_dda	initialize_dda_values(t_cub3d *game, t_point norm_dir)
{
	t_dda		dda;

	dda.delta = get_delta(norm_dir);
	dda.s_dist = calculate_side_distance(game, norm_dir, dda.delta);
	dda.steps.x = 1;
	dda.steps.y = 1;
	if (norm_dir.x < 0)
		dda.steps.x = -1;
	if (norm_dir.y < 0)
		dda.steps.y = -1;
	dda.map.x = (int)game->player.pos.x;
	dda.map.y = (int)game->player.pos.y;
	return (dda);
}
