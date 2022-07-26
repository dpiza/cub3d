/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:38:26 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/26 16:37:57 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

// static int	get_pixels_per_square(t_strmap	*map, int max_w, int max_h);

t_cub3d	*load_game(t_map	*map)
{
	t_cub3d		*game;
	t_strmap	*strMap;

	game = NULL;
	game = ft_calloc(1, sizeof(t_cub3d));
	if (!game)
		return (NULL);
	init_game_state(game);
	strMap = new_strmap();
	load_strmap(strMap, map);
	game->player.n_rays = w_width;
	strMap->minimap_pps = mm_pps;
	game->projection = new_blank_img(game->mlx, w_width,(int)(w_height * (1.0 - 0.2)));
	game->map = strMap;
	game->s_map = map;
	load_assets(game);
	load_player(game, &game->player);
	return (game);
}

int	get_pixels_per_square(t_strmap	*map, int max_w, int max_h)
{
	int	max_size[2];

	max_size[0] = max_w / map->columns;
	max_size[1] = max_h / map->lines;
	if (max_size[0] > max_size[1])
		return (max_size[1]);
	return (max_size[0]);
}
