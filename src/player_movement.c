/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:25:24 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/03 19:19:49 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	rotate_player(t_cub3d *game, float direction)
{
	float	angle;
	int		n_rays;
	float	sin_cos[2];

	angle = M_PI / (180 / 2);
	n_rays = 0;
	sin_cos[0] = sinf(angle * direction);
	sin_cos[1] = cosf(angle * direction);
	rotate_vector(sin_cos[0], sin_cos[1], &game->player.dir);
	rotate_vector(sin_cos[0], sin_cos[1], &game->player.fov_vec[0]);
	rotate_vector(sin_cos[0], sin_cos[1], &game->player.fov_vec[1]);
	while (n_rays < game->player.n_rays)
	{
		rotate_vector(sin_cos[0], sin_cos[1], &game->player.rays[n_rays]);
		n_rays++;
	}
	set_collisions(game);
}

void	move_left(t_cub3d *game)
{
	t_point	pos;
	t_point	dir;
	float	increment;

	pos = game->player.pos;
	dir = game->player.dir;
	rotate_vector(sinf(-M_PI / 2), cosf(-M_PI / 2), &dir);
	increment = MOVEMENT_STEP;
	if (get_map_obj(game, pos.x + (2 * increment * dir.x), \
		pos.y + (2 * increment * dir.y)) == '1')
		return ;
	game->player.pos.x += increment * dir.x;
	game->player.pos.y += increment * dir.y;
	set_collisions(game);
}

void	move_right(t_cub3d *game)
{
	t_point	pos;
	t_point	dir;
	float	increment;

	pos = game->player.pos;
	dir = game->player.dir;
	rotate_vector(sinf(M_PI / 2), cosf(M_PI / 2), &dir);
	increment = MOVEMENT_STEP;
	if (get_map_obj(game, pos.x + (2 * increment * dir.x), \
		pos.y + (2 * increment * dir.y)) == '1')
		return ;
	game->player.pos.x += increment * dir.x;
	game->player.pos.y += increment * dir.y;
	set_collisions(game);
}

void	move_forward(t_cub3d *game)
{
	t_point	pos;
	t_point	dir;
	int		move_xy[2];
	float	i;

	pos = game->player.pos;
	dir = game->player.dir;
	i = MOVEMENT_STEP;
	move_xy[0] = 0;
	move_xy[1] = 0;
	move_xy[0] |= get_map_obj(game, pos.x + (i * dir.x), pos.y) != '1';
	move_xy[1] |= get_map_obj(game, pos.x, pos.y + (i * dir.y)) != '1';
	if (move_xy[0])
		game->player.pos.x += i * dir.x;
	if (move_xy[1])
		game->player.pos.y += i * dir.y;
	if (move_xy[0] || move_xy[1])
		set_collisions(game);
}

void	move_backward(t_cub3d *game)
{
	t_point	pos;
	t_point	dir;
	float	increment;

	pos = game->player.pos;
	dir = game->player.dir;
	increment = MOVEMENT_STEP;
	if (get_map_obj(game, pos.x - (2 * increment * dir.x), \
		pos.y - (2 * increment * dir.y)) == '1')
		return ;
	game->player.pos.x -= increment * dir.x;
	game->player.pos.y -= increment * dir.y;
	set_collisions(game);
}
