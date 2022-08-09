/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:01:01 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/09 13:04:22 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	mouse_movement_hook(int x, int y, t_cub3d *game)
{
	if (!game->player.right_click)
		return (0);
	if (x > game->mouse_pos.x)
		rotate_player(game, ROTATE_SPEED);
	else
		rotate_player(game, -ROTATE_SPEED);
	game->mouse_pos.x = x;
	game->mouse_pos.y = y;
	return (0);
}

int	mouse_hook(int k, int x, int y, t_cub3d *game)
{
	(void)x;
	(void)y;
	if (k == RIGHT_CLICK)
		game->player.right_click = 1;
	game_loop(game);
	return (0);
}

int	mouse_release(int k, int x, int y, t_cub3d *game)
{
	(void)x;
	(void)y;
	if (k == RIGHT_CLICK)
		game->player.right_click = 0;
	game_loop(game);
	return (0);
}

int	key_hook(int k, t_cub3d *game)
{
	if (k == ESC)
		mlx_loop_end(game->mlx->mlx_ptr);
	if (k == A_KEY)
		move_left(game);
	if (k == S_KEY || k == DOWN_ARROW_KEY)
		move_backward(game);
	if (k == D_KEY)
		move_right(game);
	if (k == W_KEY || k == UP_ARROW_KEY)
		move_forward(game);
	if (k == LEFT_ARROW_KEY || k == Q_KEY)
		rotate_player(game, -2.5f);
	if (k == RIGHT_ARROW_KEY || k == E_KEY)
		rotate_player(game, 2.5f);
	game_loop(game);
	return (0);
}
