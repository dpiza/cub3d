/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:39:07 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/13 18:54:32 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	set_player_dir(t_player *player, char dir);
static void	build_player_rays(t_player *player);

void	load_player(t_cub3d	*game, t_player	*player)
{
	int			y_max;
	int			x_max;
	int			count;
	char		*map_v;
	t_strmap	*map;

	map = game->map;
	ft_bzero(player, sizeof(t_player));
	y_max = map->lines;
	x_max = map->columns;
	player->fov = 90;
	count = 0;
	player->game = game;
	player->n_rays = 10;
	player->rays = ft_calloc(player->n_rays + 1, sizeof(t_point));
	while (count < y_max * x_max)
	{
		map_v = ft_strchr("NSEW", (int)map->map[count]);
		if (map_v)
		{
			player->pos.x = (count % x_max) + 0.5;
			player->pos.y = (count / x_max) + 0.5;
			set_player_dir(player, (char)map->map[count]);
			set_fov_vectors(game);
			build_player_rays(&game->player);
			break;
		}
		count++;
	}
}

void	build_player_rays(t_player *player)
{
	t_point	dst;
	t_point	fov_fraction[w_width / 2];
	int	count;

	count = 0;
	while (count < w_width / 4)
	{
		fov_fraction[count] = player->fov_vec[0];
		multiply_vector_by_n((float)count / ((float)w_width / 4), &fov_fraction[count]);
		fov_fraction[ (w_width / 2 - 1) - count] = player->fov_vec[1];
		multiply_vector_by_n((float)count / ((float)w_width / 4), &fov_fraction[(w_width / 2 - 1) - count]);
		count++;
	}
	count = 0;
	while (count < w_width /2)
	{
		dst = sum_vectors(&player->dir, &fov_fraction[count]);
		dst = normalize_vector(dst);
		player->rays[count] = dst;
		count++;
	}
}

void	set_fov_vectors(t_cub3d *game)
{
	t_player	*player;
	float		sin_cos[2];

	player = &game->player;
	player->fov_vec[0] = player->dir;
	player->fov_vec[1] = player->dir;
	multiply_vector_by_n((float)player->fov / 90, &player->fov_vec[0]);
	multiply_vector_by_n((float)player->fov / 90, &player->fov_vec[1]);
	sin_cos[0] = sinf(- M_PI /2);
	sin_cos[1] = cosf(- M_PI /2);
	rotate_vector_new(sin_cos[0], sin_cos[1], &player->fov_vec[0]);
	sin_cos[0] = sinf(M_PI / 2);
	sin_cos[1] = cosf(M_PI / 2);
	rotate_vector_new(sin_cos[0], sin_cos[1], &player->fov_vec[1]);
}

static void	set_player_dir(t_player *player, char dir)
{
	if (dir == 'N')
	{
		player->dir.x = 0;
		player->dir.y = -1;
	}
	else if (dir == 'S')
	{
		player->dir.x = 0;
		player->dir.y = 1;
	}
	else if (dir == 'W')
	{
		player->dir.x = -1;
		player->dir.y = 0;
	}
	else if (dir == 'E')
	{
		player->dir.x = 1;
		player->dir.y = 0;
	}
}
