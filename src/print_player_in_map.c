/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player_in_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:07:08 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/23 16:15:28 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	print_player_dir(t_cub3d *game)
{
	t_point	src_xy;
	t_point	dst_xy;

	src_xy = game->player.pos;
	dst_xy = sum_vectors(&src_xy, &game->player.dir);
	multiply_vector_by_n((float)game->map->minimap_pps, &src_xy);
	multiply_vector_by_n((float)game->map->minimap_pps, &dst_xy);
	bresenham_line(game->map->minimap, src_xy.x, src_xy.y, dst_xy.x, dst_xy.y, 0xffffff );
}

void	print_player_int_map(t_cub3d *game)
{
	int		player_offset;
	t_point	scaled_pos;

	scaled_pos.x = game->player.pos.x * game->map->minimap_pps;
	scaled_pos.y = game->player.pos.y * game->map->minimap_pps;
	player_offset = get_byte_offset(game->map->minimap, scaled_pos.x, scaled_pos.y);
	print_square(game->map->minimap, (unsigned int *)(game->map->minimap->data + player_offset), 4, 0xff66ff33);
	print_player_dir(game);
}