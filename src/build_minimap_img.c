/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_minimap_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:28:08 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/28 18:36:29 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static unsigned int	get_map_color(char c);

void	build_map_img(t_cub3d *game)
{
	int				x;
	int				y;
	int				increment;
	unsigned int	*map_vector;
	t_mlx_img		*minimap;

	game->map->pos.x = 135 - (game->player.pos.x) * mm_pps;
	game->map->pos.y = 540 - (game->player.pos.y) * mm_pps;
	minimap = game->map->minimap;
	map_vector = (unsigned int *)minimap->data;
	increment = minimap->line_size / 4 * mm_pps;
	y = 0;
	while (y < game->map->lines)
	{
		x = 0;
		while (x < game->map->columns)
		{
			print_square(minimap, (map_vector + x * mm_pps), mm_pps, \
				get_map_color(game->map->map[y * game->map->columns + x]));
			x++;
		}
		map_vector += increment;
		y++;
	}
}

static unsigned int	get_map_color(char c)
{
	if (c == ' ')
		return (mm_empty);
	else if (c == '1')
		return (mm_wall);
	else if (c == '0')
		return (mm_floor);
	else
		return (mm_others);
}
