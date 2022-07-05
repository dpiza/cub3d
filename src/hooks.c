/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:01:01 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/05 14:55:04 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	rotate_player(t_cub3d *game, int direction)
{
	float	angle;

	angle = M_PI / 180 * 10;
	rotate_vector(angle * direction, &game->player.dir);
	rotate_vector(angle * direction, &game->player.fov_vec[0]);
	rotate_vector(angle * direction, &game->player.fov_vec[1]);
}

void	move_left(t_cub3d *game)
{
	t_point	pos;
	float	increment;

	pos = game->player.pos;
	increment = 0.1;
if (pos.x - increment < 1)
		return ;
	game->player.pos.x -= increment;
	print_map(game);
	print_player_int_map(game);
}

void	move_right(t_cub3d *game)
{
	t_point	pos;
	float	increment;

	pos = game->player.pos;
	increment = 0.1;
if (pos.x + increment >= game->map->columns - 1)
		return ;
	game->player.pos.x += increment;
	print_map(game);
	print_player_int_map(game);
}

void	move_down(t_cub3d *game)
{
	t_point	pos;
	float	increment;

	pos = game->player.pos;
	increment = 0.1;
if (pos.y + increment >= game->map->lines - 1)
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
	increment = 0.1;
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
		move_left(game);
		printf("a pressed\n");
	}
	if (k == 0x0073 || k == 0x0053)
	{
		move_down(game);
		printf("s pressed\n");
	}
	if (k == 0x0064 || k == 0x0044)
	{
		move_right(game);
		printf("d pressed\n");
	}
	if (k == 0x0077 || k == 0x0057)
	{
		move_up(game);
		printf("w pressed\n");
	}
	if (k == 0x0070 || k == 0x0050)
		printf("p pressed\n");
	if (k == 0xff0d)
		printf("return pressed\n");
	if (k == 0xff51)
	{
		rotate_player(game, -1);
		printf("← pressed\n");
	}
	if (k == 0xff53)
	{
		rotate_player(game, 1);
		printf("→ pressed\n");
	}
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