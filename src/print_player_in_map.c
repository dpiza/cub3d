/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player_in_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:07:08 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/25 21:17:15 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	print_rays(t_cub3d	*game)
{
	t_point	src;
	t_point	dst;
	int		n_rays;

	n_rays = 0;
	src = game->player.pos;
	multiply_vector_by_n(game->map->minimap_pps, &src);
	while (n_rays < game->player.n_rays)
	{
		//dst = get_first_collision(game, game->player.rays[n_rays]);
		//dst = get_first_collision_dda(game, game->player.rays[n_rays]);
		dst = game->player.collisions[n_rays].point;
		multiply_vector_by_n(game->map->minimap_pps, &dst);
		bresenham_line(game->map->minimap, src.x, src.y, dst.x, dst.y, player_rays);
		n_rays++;
	}
}
void	print_player_dir(t_cub3d *game)
{
	t_point	src_xy;
	t_point	dst_xy;
	t_point	fov[3];

	//set_fov_vectors(game);
	src_xy = game->player.pos;
	dst_xy = sum_vectors(&src_xy, &game->player.dir);
	fov[0] = dst_xy;
	fov[1] = sum_vectors(&fov[0], &game->player.fov_vec[0]);
	fov[2] = sum_vectors(&fov[0], &game->player.fov_vec[1]);
	multiply_vector_by_n((float)game->map->minimap_pps, &src_xy);
	multiply_vector_by_n((float)game->map->minimap_pps, &dst_xy);
	multiply_vector_by_n((float)game->map->minimap_pps, &fov[0]);
	multiply_vector_by_n((float)game->map->minimap_pps, &fov[1]);
	multiply_vector_by_n((float)game->map->minimap_pps, &fov[2]);
	//bresenham_line(game->map->minimap, src_xy.x, src_xy.y, dst_xy.x, dst_xy.y, 0xffffff );
	//bresenham_line(game->map->minimap, dst_xy.x, dst_xy.y, fov[1].x, fov[1].y, 0xffffff );
	//bresenham_line(game->map->minimap, dst_xy.x, dst_xy.y, fov[2].x, fov[2].y, 0xffffff );
}



void	print_player_int_map(t_cub3d *game)
{
	int		player_offset;
	t_point	scaled_pos;

	scaled_pos.x = (game->player.pos.x - 0.5) * game->map->minimap_pps;
	scaled_pos.y = (game->player.pos.y - 0.5) * game->map->minimap_pps;
	player_offset = get_byte_offset(game->map->minimap, scaled_pos.x, scaled_pos.y);
	print_square(game->map->minimap, (unsigned int *)(game->map->minimap->data + player_offset), mm_pps, mm_player);
	print_rays(game);
	print_player_dir(game);
}