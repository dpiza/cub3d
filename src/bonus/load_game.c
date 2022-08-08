/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:38:26 by hde-camp          #+#    #+#             */
/*   Updated: 2022/08/07 20:38:52 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

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
	game->player.n_rays = W_WIDTH;
	height = (int)(W_HEIGHT * (1.0 - 0.2));
	game->projection = new_blank_img(game->mlx, W_WIDTH, height);
	game->map = str_map;
	game->s_map = map;
	game->map->minimap = new_blank_img(game->mlx, game->map->columns * MM_PPS, \
		game->map->lines * MM_PPS);
	load_assets(game);
	load_player(game, &game->player);
	game->player.health = 100;
	get_map_sprites(game, str_map);
	return (game);
}

int	init_game_state(t_cub3d *game)
{
	game->mlx = ft_calloc(1, sizeof(t_mlx));
	game->mlx->mlx_ptr = mlx_init();
	if (game->mlx->mlx_ptr)
		return (1);
	return (0);
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
