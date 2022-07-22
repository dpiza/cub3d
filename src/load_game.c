/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:38:26 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/22 12:35:00 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	get_pixels_per_square(t_strmap	*map, int max_w, int max_h);

t_cub3d	*load_game(t_map	*map)
{
	t_cub3d		*game;
	int			pps;

	game = NULL;
	game = ft_calloc(1, sizeof(t_cub3d));
	if (!game)
		return (NULL);
	game->map = new_strmap();
	load_strmap(game->map, map);
	pps = get_pixels_per_square(game->map, w_width / 4 , w_height);
	game->map->minimap_pps = pps;
	game->map->pos.x = (((w_width / 4) - pps * game->map->columns) / 2) + 10;
	game->map->pos.y = ((w_height - pps * game->map->lines) / 1) - 10;
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
