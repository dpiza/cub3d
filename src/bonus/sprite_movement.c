/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:01:54 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/07 20:41:09 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	update_map_position(t_cub3d *game, t_sprite *sprite, t_point new_pos)
{
	if (((int)sprite->pos.x != (int)new_pos.x
			|| (int)sprite->pos.y != (int)new_pos.y))
	{
		game->map->map[(int)sprite->pos.y * \
			game->map->columns + (int)sprite->pos.x] = '0';
		game->map->map[(int)new_pos.y * \
			game->map->columns + (int)new_pos.x] = 'X';
	}
}

void	move_closer(t_cub3d *game, t_sprite *sprite)
{
	t_point		difference;
	t_int_point	is_collision;
	t_point		new_position;

	if (sprite->distance < 5 && sprite->enabled)
		sprite->aggro = 1;
	if (sprite->aggro && sprite->distance > 1
		&& sprite->enabled
		&& sprite->tick > ANIMATION_CICLE)
	{
		difference.x = sprite->pos.x - game->player.pos.x;
		difference.y = sprite->pos.y - game->player.pos.y;
		difference = normalize_vector(difference);
		is_collision.x = is_in_list(get_map_obj(game, sprite->pos.x + \
			(3 * MOVEMENT_STEP * -difference.x), sprite->pos.y), MAP_OBSTACLE);
		is_collision.y = is_in_list(get_map_obj(game, sprite->pos.x, \
			sprite->pos.y + (3 * MOVEMENT_STEP * -difference.y)), MAP_OBSTACLE);
		new_position = sprite->pos;
		if (!is_collision.x)
			new_position.x = sprite->pos.x + MOVEMENT_STEP / 2 * -difference.x;
		if (!is_collision.y)
			new_position.y = sprite->pos.y + MOVEMENT_STEP / 2 * -difference.y;
		update_map_position(game, sprite, new_position);
		sprite->pos = new_position;
	}
}

void	damage_player(t_cub3d *game, t_sprite *sprite)
{
	if (sprite->distance < 1 && sprite->enabled
		&& sprite->tick > ANIMATION_CICLE)
	{
		game->player.health -= 2;
		game->player.damaged = 5;
	}
}
