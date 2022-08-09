/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:01:01 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/09 12:36:05 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

int	mouse_movement(int x, int y, t_cub3d *game)
{
	if (game->player.in_conversation)
		return (0);
	if (game->player.right_click)
		rotate_player(game, (x - game->mouse_pos.x) * ROTATE_SPEED);
	game->mouse_pos.x = x;
	game->mouse_pos.y = y;
	return (0);
}

int	mouse_click(int k, int x, int y, t_cub3d *game)
{
	(void)x;
	if (game->player.in_conversation)
		return (0);
	if (k == LEFT_CLICK && y < 476)
		fire(game);
	if (k == LEFT_CLICK && y > 476)
		game->player.left_click = 1;
	if (k == RIGHT_CLICK)
		game->player.right_click = 1;
	return (0);
}

int	mouse_release(int k, int x, int y, t_cub3d *game)
{
	if (game->player.in_conversation)
		return (0);
	if (k == LEFT_CLICK)
		game->player.left_click = 0;
	if (k == LEFT_CLICK && y > 476)
		game_menu(game, x, y);
	if (k == RIGHT_CLICK)
	{
		mlx_mouse_move(game->mlx->mlx_ptr, \
			game->mlx->win_ptr, W_WIDTH / 2, 240);
		game->player.right_click = 0;
	}
	return (0);
}

int	key_hook(int k, t_cub3d *game)
{
	if (game->player.in_conversation && k != 0x0065 && k != 0xff1b)
		return (0);
	if (k == ESC)
		mlx_loop_end(game->mlx->mlx_ptr);
	if (k == W_KEY || k == UP_ARROW_KEY)
		move_forward(game);
	if (k == A_KEY)
		move_left(game);
	if (k == S_KEY || k == DOWN_ARROW_KEY)
		move_backward(game);
	if (k == D_KEY)
		move_right(game);
	if (k == LEFT_ARROW_KEY)
		rotate_player(game, -2.5f);
	if (k == RIGHT_ARROW_KEY)
		rotate_player(game, 2.5f);
	if (k == E_KEY)
		use(game);
	if (k == R_KEY)
		reload(game);
	game_loop(game);
	return (0);
}
