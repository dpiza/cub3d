/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vector_collision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:43:26 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/28 18:53:39 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_collision	get_collision(t_cub3d *game, t_point norm_dir)
{
	t_collision	collision;
	t_dda		dda;

	dda = initialize_dda_values(game, norm_dir);
	collision.side = NA;
	while (collision.side == NA)
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
		if (get_map_obj(game, (float)dda.map.x, (float)dda.map.y) == '1')
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
}
