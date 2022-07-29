/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:16:56 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/28 21:05:20 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	game_loop(t_cub3d *game)
{
	build_map(game);
	print_player_int_map(game);
	build_projection(game);
	print_bar_screen(game);
	print_map(game);
	print_projection(game);
	print_weapon(game);
	print_bar(game);
	print_crosshair(game);
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr, \
		game->mlx->img->img_ptr, 0, 0);
	print_stats(game);
	game->tick++;
	return (0);
}

void	game_run(t_cub3d	*game)
{
	game->mlx->win_ptr = mlx_new_window(game->mlx->mlx_ptr, W_WIDTH, \
		W_HEIGHT, "Nuk3d");
	game->mlx->img = new_blank_img(game->mlx, W_WIDTH, W_HEIGHT);
	mlx_hook(game->mlx->win_ptr, 17, 0L, mlx_loop_end, game->mlx->mlx_ptr);
	mlx_hook(game->mlx->win_ptr, 2, 1L << 0, key_hook, game);
	mlx_hook(game->mlx->win_ptr, 5, 1L << 3, mouse_release, game);
	mlx_hook(game->mlx->win_ptr, 6, 1L << 6, mouse_movement_hook, game);
	mlx_mouse_hook(game->mlx->win_ptr, mouse_hook, game);
	mlx_loop_hook(game->mlx->mlx_ptr, game_loop, game);
	mlx_loop(game->mlx->mlx_ptr);
	gracefull_shutdown(game);
}
