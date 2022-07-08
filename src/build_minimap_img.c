/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_minimap_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:28:08 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/07 21:39:42 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static unsigned int	get_map_color(char c);

void	build_map_img(t_cub3d *game)
{
	int				x;
	int				y;
	unsigned int	*map_vector;
	t_mlx_img		*minimap;

	if (!game->map->minimap)
	{
		minimap = new_blank_img(game->mlx, game->map->columns * game->map->minimap_pps, game->map->lines * game->map->minimap_pps);
		game->map->minimap = minimap;
	}
	else
		minimap = game->map->minimap;
	map_vector = (unsigned int *)minimap->data;
	y = 0;
	while (y < game->map->lines)
	{
		x = 0;
		while (x < game->map->columns)
		{
			print_square(minimap, (map_vector + x * game->map->minimap_pps), game->map->minimap_pps, get_map_color(game->map->map[y* game->map->columns + x]));
			x++;
		}
		map_vector += minimap->line_size / 4 * game->map->minimap_pps;
		y++;
	}
}

static unsigned int	get_map_color(char c)
{
	if (c == ' ')
		return (0x00ffffff);
	else if(c == '1')
		return (0x009c000d);
	else if(c == '0')
		return (0x00ff924f);
	else
		return (0x008a4f00);
}
