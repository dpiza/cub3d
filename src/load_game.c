/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:38:26 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/22 14:46:38 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	get_pixels_per_square(t_strmap	*map, int max_w, int max_h);

t_cub3d	*load_game(t_map	*map)
{
	t_cub3d		*game;
	t_strmap	*strMap;
	int			pps;

	game = NULL;
	game = ft_calloc(1, sizeof(t_cub3d));
	if (!game)
		return (NULL);
	strMap = new_strmap();
	load_strmap(strMap, map);
	strMap->XYfactor[0] = 0.25;
	strMap->XYfactor[1] = 0.25;
	game->player.n_rays = strMap->XYfactor[0] * w_width;
	pps = get_pixels_per_square(strMap, strMap->XYfactor[0] * w_width, strMap->XYfactor[1] * w_height);
	strMap->minimap_pps = pps;
	strMap->pos.x = (((w_width / 4) - pps * strMap->columns) / 2) + 10;
	strMap->pos.y = ((w_height - pps * strMap->lines) / 1) - 10;
	game->map = strMap;
	load_player(game, &game->player);
	return (game);
}

static int	get_pixels_per_square(t_strmap	*map, int max_w, int max_h)
{
	int	max_size[2];

	max_size[0] = max_w / map->columns;
	max_size[1] = max_h / map->lines;
	if (max_size[0] > max_size[1])
		return (max_size[1]);
	return (max_size[0]);
}
