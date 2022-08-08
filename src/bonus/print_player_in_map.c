/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player_in_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:07:08 by hde-camp          #+#    #+#             */
/*   Updated: 2022/08/07 20:40:41 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	print_rays(t_cub3d	*game)
{
	t_point		aux;
	t_int_point	src;
	t_int_point	dst;
	int			n_rays;

	n_rays = 0;
	aux = game->player.pos;
	multiply_vector_by_n(MM_PPS, &aux);
	src.x = (int)aux.x;
	src.y = (int)aux.y;
	while (n_rays < game->player.n_rays)
	{
		aux = game->player.collisions[n_rays].point;
		multiply_vector_by_n(MM_PPS, &aux);
		dst.x = aux.x;
		dst.y = aux.y;
		bresenham_line(game->map->minimap, src, dst, PLAYER_RAYS);
		n_rays++;
	}
}

void	print_player_in_map(t_cub3d *game)
{
	int				offset;
	unsigned int	*pixel;
	t_point			pos;

	pos.x = (game->player.pos.x - 0.5) * MM_PPS;
	pos.y = (game->player.pos.y - 0.5) * MM_PPS;
	offset = get_byte_offset(game->map->minimap, pos.x, pos.y);
	pixel = (game->map->minimap->data + offset);
	print_square(game->map->minimap, pixel, MM_PPS, MM_PLAYER);
	print_rays(game);
}
