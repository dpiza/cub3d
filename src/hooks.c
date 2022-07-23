/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:01:01 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/23 16:16:37 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	player_pos(t_cub3d *game)
{
	printf("Player.x: %f Player.y: %f\n", game->player.pos.x, game->player.pos.y);
}

void	rotate_player(t_cub3d *game, int direction)
{
	float	angle;
	int		n_rays;
	float	sin_cos[2];

	angle = M_PI / (180 / 2);
	n_rays = 0;
	sin_cos[0] = sinf(angle * direction);
	sin_cos[1] = cosf(angle * direction);
	rotate_vector_new(sin_cos[0], sin_cos[1], &game->player.dir);
	rotate_vector_new(sin_cos[0], sin_cos[1], &game->player.fov_vec[0]);
	rotate_vector_new(sin_cos[0], sin_cos[1], &game->player.fov_vec[1]);
	while (n_rays < game->player.n_rays)
	{
		rotate_vector_new(sin_cos[0], sin_cos[1], &game->player.rays[n_rays]);
		n_rays++;
	}
	set_collisions(game);
}

void	move_left(t_cub3d *game)
{
	t_point	pos;
	float	increment;

	pos = game->player.pos;
	increment = 0.25;
	if (pos.x - increment < 1)
		return ;
	if (square_check(game, pos.x - increment, pos.y) == '1')
		return ;	
	game->player.pos.x -= increment;
	set_collisions(game);
	print_map(game);
	print_player_int_map(game);
}

void	move_right(t_cub3d *game)
{
	t_point	pos;
	float	increment;

	pos = game->player.pos;
	increment = 0.25;
	if (pos.x + increment >= game->map->columns - 1)
		return ;
	if (square_check(game, pos.x + increment, pos.y) == '1')
		return ;
	game->player.pos.x += increment;
	set_collisions(game);
	print_map(game);
	print_player_int_map(game);
}

void	move_forward(t_cub3d *game)
{
	t_point	pos;
	t_point	dir;
	float	increment;
	float	increment_x;
	float	increment_y;

	pos = game->player.pos;
	dir = game->player.dir;
	increment = 0.25;
	increment_x = increment * dir.x;
	increment_y = increment * dir.y;
	// if (pos.y - increment_y < 1 || pos.x - increment_x < 1)
	// 	return ;
	if (square_check(game, pos.x + increment_x, pos.y + increment_y) == '1')
		return ;
	game->player.pos.x += increment_x;
	game->player.pos.y += increment_y;
	set_collisions(game);
	print_map(game);
	print_player_int_map(game);
}

void	move_backward(t_cub3d *game)
{
	t_point	pos;
	t_point	dir;
	float	increment;
	float	increment_x;
	float	increment_y;

	pos = game->player.pos;
	dir = game->player.dir;
	increment = 0.25;
	increment_x = increment * dir.x;
	increment_y = increment * dir.y;
	// if (pos.y - increment_y < 1 || pos.x - increment_x < 1)
	// 	return ;
	if (square_check(game, pos.x - increment_x, pos.y - increment_y) == '1')
		return ;
	game->player.pos.x -= increment_x;
	game->player.pos.y -= increment_y;
	set_collisions(game);
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
		// printf("a pressed\n");
	}
	if (k == 0x0073 || k == 0x0053)
	{
		move_backward(game);
		// move_down(game);
		// printf("s pressed\n");
	}
	if (k == 0x0064 || k == 0x0044)
	{
		move_right(game);
		// printf("d pressed\n");
	}
	if (k == 0x0077 || k == 0x0057)
	{
		move_forward(game);
		// move_up(game);
		// printf("w pressed\n");
	}
	if (k == 0x0070 || k == 0x0050)
		printf("p pressed\n");
	if (k == 0xff0d)
		printf("return pressed\n");
	if (k == 0xff51)
	{
		rotate_player(game, -1);
		// printf("← pressed\n");
	}
	if (k == 0xff53)
	{
		rotate_player(game, 1);
		// printf("→ pressed\n");
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
	build_projection(game);
	print_projection(game);
	// player_pos(game); // printa a posição do player no terminal
	game_loop(game); // chama a função que printa o jogo na tela apenas quando há movimento
	
	return (0);
}