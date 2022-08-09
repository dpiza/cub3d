/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:25:24 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/07 20:40:18 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	rotate_player(t_cub3d *game, float direction)
{
	float	angle;
	int		n_rays;
	float	sin_cos[2];

	angle = 0.084F;
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
	game->player.angle = atan2(-game->player.dir.y, game->player.dir.x) * \
		TO_DEGREE;
	if (game->player.angle > 360)
		game->player.angle -= 360;
	if (game->player.angle < 0)
		game->player.angle += 360;
}

void	move_left(t_cub3d *game)
{
	t_point	pos;
	t_point	dir;
	t_point	is_collision;

	is_collision.x = 0;
	is_collision.y = 0;
	pos = game->player.pos;
	dir = game->player.dir;
	rotate_vector(sinf(-M_PI / 2), cosf(-M_PI / 2), &dir);
	is_collision.x = is_in_list(get_map_obj(game, pos.x + \
		(2 * MOVEMENT_STEP * dir.x), pos.y), MAP_OBSTACLE);
	is_collision.y = is_in_list(get_map_obj(game, pos.x, \
		pos.y + (2 * MOVEMENT_STEP * dir.y)), MAP_OBSTACLE);
	if (!is_collision.x)
		game->player.pos.x += MOVEMENT_STEP * dir.x;
	if (!is_collision.y)
		game->player.pos.y += MOVEMENT_STEP * dir.y;
	set_collisions(game);
}

void	move_right(t_cub3d *game)
{
	t_point	pos;
	t_point	dir;
	t_point	is_collision;

	is_collision.x = 0;
	is_collision.y = 0;
	pos = game->player.pos;
	dir = game->player.dir;
	rotate_vector(sinf(M_PI / 2), cosf(M_PI / 2), &dir);
	is_collision.x = is_in_list(get_map_obj(game, pos.x + \
		(2 * MOVEMENT_STEP * dir.x), pos.y), MAP_OBSTACLE);
	is_collision.y = is_in_list(get_map_obj(game, pos.x, \
		pos.y + (2 * MOVEMENT_STEP * dir.y)), MAP_OBSTACLE);
	if (!is_collision.x)
		game->player.pos.x += MOVEMENT_STEP * dir.x;
	if (!is_collision.y)
		game->player.pos.y += MOVEMENT_STEP * dir.y;
	set_collisions(game);
}

void	move_forward(t_cub3d *game)
{
	t_point	pos;
	t_point	dir;
	t_point	is_collision;

	is_collision.x = 0;
	is_collision.y = 0;
	pos = game->player.pos;
	dir = game->player.dir;
	is_collision.x = is_in_list(get_map_obj(game, pos.x + \
		(2 * MOVEMENT_STEP * dir.x), pos.y), MAP_OBSTACLE);
	is_collision.y = is_in_list(get_map_obj(game, pos.x, \
		pos.y + (2 * MOVEMENT_STEP * dir.y)), MAP_OBSTACLE);
	if (!is_collision.x)
		game->player.pos.x += MOVEMENT_STEP * dir.x;
	if (!is_collision.y)
		game->player.pos.y += MOVEMENT_STEP * dir.y;
	set_collisions(game);
}

void	move_backward(t_cub3d *game)
{
	t_point	pos;
	t_point	dir;
	t_point	is_collision;

	is_collision.x = 0;
	is_collision.y = 0;
	pos = game->player.pos;
	dir = game->player.dir;
	is_collision.x = is_in_list(get_map_obj(game, pos.x - \
		(2 * MOVEMENT_STEP * dir.x), pos.y), MAP_OBSTACLE);
	is_collision.y = is_in_list(get_map_obj(game, pos.x, \
		pos.y - (2 * MOVEMENT_STEP * dir.y)), MAP_OBSTACLE);
	if (!is_collision.x)
		game->player.pos.x -= MOVEMENT_STEP * dir.x;
	if (!is_collision.y)
		game->player.pos.y -= MOVEMENT_STEP * dir.y;
	set_collisions(game);
}
