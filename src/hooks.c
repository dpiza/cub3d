/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:01:01 by dpiza             #+#    #+#             */
/*   Updated: 2022/05/14 01:01:52 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	move_down(t_cub3d *game)
{
	t_point	pos;
	float	increment;

	pos = game->player.pos;
	increment = 0.5;
	if (pos.y + increment > game->map->lines - 2)
		return ;
	game->player.pos.y += increment;
	print_map(game);
	print_player_int_map(game);
}

void	move_up(t_cub3d *game)
{
	t_point	pos;
	float	increment;

	pos = game->player.pos;
	increment = 0.5;
	if (pos.y - increment < 1)
		return ;
	game->player.pos.y -= increment;
	print_map(game);
	print_player_int_map(game);
}

int	key_hook(int k, t_cub3d *game)
{
	if (k == 0xff1b) // ESC
		mlx_loop_end(game->mlx->mlx_ptr);
	if (k == 0x0061 || k == 0x0041)
	{
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr, game->mlx->img->img_ptr, 0, 0);
		printf("a pressed\n");
	}
	if (k == 0x0073 || k == 0x0053)
	{
		move_down(game);
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr, game->mlx->img->img_ptr, 0, 0);
		printf("s pressed\n");
	}
	if (k == 0x0064 || k == 0x0044)
		printf("d pressed\n");
	if (k == 0x0077 || k == 0x0057)
	{
		move_up(game);
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr, game->mlx->img->img_ptr, 0, 0);
		printf("w pressed\n");
	}
	if (k == 0x0070 || k == 0x0050)
		printf("p pressed\n");
	if (k == 0xff0d)
		printf("return pressed\n");
	/*
	teclas de interesse:
				normal		UPPERCASE
	a			0x0061		0x0041
	s			0x0073		0x0053
	d			0x0064		0x0044
	w			0x0077		0x0057
	p			0x0070		0x0050
	escape		0xff1b
	enter		0xff0d
	uparrow		0xff52
	downarrow	0xff54
	leftarrow	0xff51
	rightarrow	0xff53
	*/
	return (0);
}