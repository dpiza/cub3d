/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:43:26 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/07 20:38:09 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

t_collision	get_collision(t_cub3d *game, t_point norm_dir)
{
	t_collision	collision;
	t_dda		dda;

	dda = initialize_dda_values(game, norm_dir);
	while (!is_in_list(dda.map_obj, MAP_COLLISION))
	{
		if (dda.s_dist.x < dda.s_dist.y)
		{
			dda.w_dist = dda.s_dist.x;
			dda.s_dist.x += dda.delta.x;
			dda.map.x += dda.steps.x;
			dda.side = 1;
		}
		else
		{
			dda.w_dist = dda.s_dist.y;
			dda.s_dist.y += dda.delta.y;
			dda.map.y += dda.steps.y;
			dda.side = 0;
		}
		dda.map_obj = get_map_obj(game, (float)dda.map.x, (float)dda.map.y);
		if (is_in_list(dda.map_obj, MAP_COLLISION))
			collision = ret_collision_result(game, &norm_dir, dda);
	}
	return (collision);
}

void	set_collisions(t_cub3d	*game)
{
	int			n_rays;
	t_collision	*collision;
	t_point		*ray;

	n_rays = 0;
	while (n_rays < game->player.n_rays)
	{
		collision = &game->player.collisions[n_rays];
		ray = &game->player.rays[n_rays];
		*collision = get_collision(game, *ray);
		n_rays++;
	}
	update_sprites_distance(game);
	sort_sprite_list(game);
}

t_collision	sprite_collision_result(t_cub3d *game, t_point *norm_dir, t_dda dda)
{
	t_collision	collision;

	collision.map_obj = dda.map_obj;
	collision.point = axis_collision(game->player.pos, *norm_dir, dda.w_dist);
	collision.distance = dda.w_dist;
	collision.perp_distance = dda.w_dist * \
		(norm_dir->x * game->player.dir.x + norm_dir->y * game->player.dir.y);
	if (collision.point.x - (int)collision.point.x == 0)
	{
		if (collision.point.x < game->player.pos.x)
			collision.point.x -= 1;
	}
	if (collision.point.y - (int)collision.point.y == 0)
	{
		if (collision.point.y < game->player.pos.y)
			collision.point.y -= 1;
	}
	return (collision);
}

t_collision	get_sprite_collision(t_cub3d *game)
{
	t_collision	collision;
	t_dda		dda;

	dda = initialize_dda_values(game, game->player.dir);
	while (!is_in_list(dda.map_obj, SHOOTING_OBST))
	{
		if (dda.s_dist.x < dda.s_dist.y)
		{
			dda.w_dist = dda.s_dist.x;
			dda.s_dist.x += dda.delta.x;
			dda.map.x += dda.steps.x;
			dda.side = 1;
		}
		else
		{
			dda.w_dist = dda.s_dist.y;
			dda.s_dist.y += dda.delta.y;
			dda.map.y += dda.steps.y;
			dda.side = 0;
		}
		dda.map_obj = get_map_obj(game, (float)dda.map.x, (float)dda.map.y);
		if (is_in_list(dda.map_obj, SHOOTING_OBST))
			collision = sprite_collision_result(game, &game->player.dir, dda);
	}
	return (collision);
}
