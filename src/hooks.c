/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:01:01 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/28 11:27:54 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	reload(t_cub3d *game)
{
	if (game->player.firing == 0 && game->player.ammo == 0)
	{
		game->player.ammo = 15;
		game->player.firing = -12;
	}
}

int	key_hook(int k, t_cub3d *game)
{
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
	if (k == 0xff51 || k == 0x0071)
		rotate_player(game, -2.5f);
	if (k == 0xff53 || k == 0x0065)
		rotate_player(game, 2.5f);
	if (k == 0x0072)
		reload(game);
	if (k == 0x0070 || k == 0x0050)
		printf("p pressed\n");
	if (k == 0xff0d)
		printf("return pressed\n");
	printf("%i pressed\n", k);
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