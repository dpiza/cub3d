/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player_in_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:07:08 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/05 19:47:03 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	print_rays(t_cub3d	*game)
{
	t_point	src;
	t_point	dst;
	t_point	fov_fraction[w_width / 2];
	int	count;

	src = game->player.pos;
	multiply_vector_by_n(game->map->minimap_pps, &src);
	count = 0;
	while (count < w_width / 4)
	{
		fov_fraction[count] = game->player.fov_vec[0];
		multiply_vector_by_n((float)count / ((float)w_width / 4), &fov_fraction[count]);
		fov_fraction[ (w_width / 2 - 1) - count] = game->player.fov_vec[1];
		multiply_vector_by_n((float)count / ((float)w_width / 4), &fov_fraction[(w_width / 2 - 1) - count]);
		count++;
	}
	count = 0;
	while (count < w_width / 2)
	{
		dst = sum_vectors(&game->player.dir, &game->player.pos);
		game->player.rays[count] = sum_vectors(&fov_fraction[count], &dst);
		dst = game->player.rays[count];
		multiply_vector_by_n(game->map->minimap_pps, &dst);
		bresenham_line(game->map->minimap, src.x, src.y, dst.x, dst.y, 0xffffff );
		count++;
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
	print_rays(game);
	bresenham_line(game->map->minimap, src_xy.x, src_xy.y, dst_xy.x, dst_xy.y, 0xffffff );
	bresenham_line(game->map->minimap, dst_xy.x, dst_xy.y, fov[1].x, fov[1].y, 0xffffff );
	bresenham_line(game->map->minimap, dst_xy.x, dst_xy.y, fov[2].x, fov[2].y, 0xffffff );
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