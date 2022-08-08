/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:28:08 by hde-camp          #+#    #+#             */
/*   Updated: 2022/08/07 20:37:30 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static unsigned int	get_map_color(char c);

void	build_map(t_cub3d *game)
{
	int				x;
	int				y;
	int				increment;
	unsigned int	*map_vector;
	t_mlx_img		*minimap;

	game->map->pos.x = 135 - (game->player.pos.x) * MM_PPS;
	game->map->pos.y = 540 - (game->player.pos.y) * MM_PPS;
	minimap = game->map->minimap;
	map_vector = (unsigned int *)minimap->data;
	increment = minimap->line_size / 4 * MM_PPS;
	y = 0;
	while (y < game->map->lines)
	{
		x = 0;
		while (x < game->map->columns)
		{
			print_square(minimap, (map_vector + x * MM_PPS), MM_PPS, \
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
		return (MM_EMPTY);
	else if (c == '1')
		return (MM_WALL);
	else if (c == '0')
		return (MM_FLOOR);
	else if (is_in_list(c, MINIMAP_DOOR))
		return (MM_DOOR);
	else
		return (MM_OTHERS);
}
