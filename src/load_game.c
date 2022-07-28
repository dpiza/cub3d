/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:38:26 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/27 18:51:16 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_cub3d	*load_game(t_map	*map)
{
	t_cub3d		*game;
	t_strmap	*str_map;
	int			height;

	game = NULL;
	game = ft_calloc(1, sizeof(t_cub3d));
	if (!game)
		return (NULL);
	init_game_state(game);
	str_map = new_strmap();
	load_strmap(str_map, map);
	game->player.n_rays = w_width;
	str_map->minimap_pps = mm_pps;
	height = (int)(w_height * (1.0 - 0.2));
	game->projection = new_blank_img(game->mlx, w_width, height);
	game->map = str_map;
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
