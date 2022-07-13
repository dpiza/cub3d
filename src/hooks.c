/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:01:01 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/13 18:56:36 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	square_check(t_cub3d *game, float x, float y)
{
	int		pos_array;
	char	map_obj;
	
	pos_array = (int)game->map->columns * (int)y + (int)x;
	map_obj = game->map->map[pos_array];
	// printf("Map obj %c\n", map_obj); // printa o objeto do mapa no terminal
	return (map_obj);
}

char	square_dir_check(t_cub3d *game, t_point *collision, t_point *dir)
{
	int		pos_array;
	char	map_obj;
	int		round_factor;
	int		xy[2];
	int		map_len;

	round_factor = 100000000;
	if ( ((int)(collision->x * round_factor)) % round_factor == 0 ) //colisao em x
	{
		if (dir->x > 0)
			xy[0] = (int)collision->x;
		else
			xy[0] = ((int)collision->x) - 1;
		xy[1] = (int)collision->y;
	}
	else//colisao em y
	{
		if (dir->y > 0)
			xy[1] = (int)collision->y;
		else
			xy[1] = ((int)collision->y) - 1;
		xy[0] = (int)collision->x;
	}
	pos_array = (int)game->map->columns * xy[1] + xy[0];
	map_obj = '1';
	map_len = ft_strlen(game->map->map);
	if (pos_array >= 0 && pos_array < map_len)
	{
		map_obj = game->map->map[pos_array];
	}
	return (map_obj);
}

void	player_pos(t_cub3d *game)
{
	printf("Player.x: %f Player.y: %f\n", game->player.pos.x, game->player.pos.y);
}

void	rotate_player(t_cub3d *game, int direction)
{
	float	angle;
	int		n_rays;
	float	sin_cos[2];

	angle = M_PI / 180 * 10;
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
}

void	move_left(t_cub3d *game)
{
	t_point	pos;
	float	increment;

	pos = game->player.pos;
	increment = 0.1;
	if (pos.x - increment < 1)
		return ;
	if (square_check(game, pos.x - increment, pos.y) == '1')
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
	if (square_check(game, pos.x + increment, pos.y) == '1')
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
	if (square_check(game, pos.x, pos.y + increment) == '1')
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
	if (square_check(game, pos.x, pos.y - increment) == '1')
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

	player_pos(game); // printa a posição do player no terminal
	game_loop(game); // chama a função que printa o jogo na tela apenas quando há movimento
	
	return (0);
}