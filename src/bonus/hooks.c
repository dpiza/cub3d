/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:01:01 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/07 20:38:33 by dpiza            ###   ########.fr       */
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
	if (k == 1 && y < 476)
		fire(game);
	if (k == 1 && y > 476)
		game->player.left_click = 1;
	if (k == 3)
		game->player.right_click = 1;
	return (0);
}

int	mouse_release(int k, int x, int y, t_cub3d *game)
{
	if (game->player.in_conversation)
		return (0);
	if (k == 3)
	{
		mlx_mouse_move(game->mlx->mlx_ptr, \
			game->mlx->win_ptr, W_WIDTH / 2, 240);
		game->player.right_click = 0;
	}
	if (k == 1 && y > 476)
		game_menu(game, x, y);
	if (k == 1)
		game->player.left_click = 0;
	return (0);
}

int	key_hook(int k, t_cub3d *game)
{
	if (game->player.in_conversation && k != 0x0065 && k != 0xff1b)
		return (0);
	if (k == 0xff1b)
		mlx_loop_end(game->mlx->mlx_ptr);
	if (k == 0x0061 || k == 0x0041)
		move_left(game);
	if (k == 0x0073 || k == 0x0053 || k == 0xff54)
		move_backward(game);
	if (k == 0x0064 || k == 0x0044)
		move_right(game);
	if (k == 0x0077 || k == 0x0057 || k == 0xff52)
		move_forward(game);
	if (k == 0xff51)
		rotate_player(game, -2.5f);
	if (k == 0xff53)
		rotate_player(game, 2.5f);
	if (k == 0x0065)
		use(game);
	if (k == 0x0072)
		reload(game);
	game_loop(game);
	return (0);
}
	/*
	teclas de interesse:
				normal		UPPERCASE
	a			0x0061		0x0041
	s			0x0073		0x0053
	d			0x0064		0x0044
	w			0x0077		0x0057
	p			0x0070		0x0050
	q			0x0071
	e			0x0065
	r			0x0072
	escape		0xff1b
	enter		0xff0d
	uparrow		0xff52
	downarrow	0xff54
	leftarrow	0xff51
	rightarrow	0xff53
	space		0x0020
	*/