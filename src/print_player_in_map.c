/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player_in_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:07:08 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/27 17:49:38 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	print_rays(t_cub3d	*game)
{
	t_point		aux;
	t_int_point	src;
	t_int_point	dst;
	int			n_rays;

	n_rays = 0;
	aux = game->player.pos;
	multiply_vector_by_n(game->map->minimap_pps, &aux);
	src.x = (int)aux.x;
	src.y = (int)aux.y;
	while (n_rays < game->player.n_rays)
	{
		aux = game->player.collisions[n_rays].point;
		multiply_vector_by_n(game->map->minimap_pps, &aux);
		dst.x = aux.x;
		dst.y = aux.y;
		bresenham_line(game->map->minimap, src, dst, player_rays);
		n_rays++;
	}
}

void	print_player_int_map(t_cub3d *game)
{
	int				offset;
	unsigned int	*pixel;
	t_point			pos;

	pos.x = (game->player.pos.x - 0.5) * game->map->minimap_pps;
	pos.y = (game->player.pos.y - 0.5) * game->map->minimap_pps;
	offset = get_byte_offset(game->map->minimap, pos.x, pos.y);
	pixel = (game->map->minimap->data + offset);
	print_square(game->map->minimap, pixel, mm_pps, mm_player);
	print_rays(game);
}
