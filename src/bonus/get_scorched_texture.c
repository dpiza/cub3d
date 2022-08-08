/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scorched_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:06:31 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/07 20:38:29 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

t_mlx_img	*get_scorched_shot(t_cub3d *game, t_sprite *sprite)
{
	t_mlx_img	*texture;

	texture = game->texture.scor16;
	if (sprite->shot < ANIMATION_CICLE)
	{
		texture = game->texture.scor16;
		sprite->shot++;
	}
	else
		sprite->shot = 0;
	return (texture);
}

t_mlx_img	*get_scorched_alive(t_cub3d *game, t_sprite *sprite)
{
	t_mlx_img	*texture;

	texture = game->texture.scor02;
	if (sprite->tick > 2 * ANIMATION_CICLE)
		sprite->tick = 0;
	if (sprite->tick < ANIMATION_CICLE)
		texture = game->texture.scor02;
	else if (sprite->tick < 2 * ANIMATION_CICLE)
		texture = game->texture.scor03;
	sprite->tick++;
	return (texture);
}

t_mlx_img	*get_scorched_dead(t_cub3d *game, t_sprite *sprite)
{
	t_mlx_img	*texture;

	texture = game->texture.scor20;
	if (sprite->tick > 0)
		sprite->tick = -1;
	if (sprite->tick > -ANIMATION_CICLE)
		texture = game->texture.scor16;
	else if (sprite->tick > 2 * -ANIMATION_CICLE)
		texture = game->texture.scor17;
	else if (sprite->tick > 3 * -ANIMATION_CICLE)
		texture = game->texture.scor18;
	else if (sprite->tick > 4 * -ANIMATION_CICLE)
		texture = game->texture.scor19;
	else if (sprite->tick > 5 * -ANIMATION_CICLE)
	{
		sprite->enabled = 0;
		sprite->tick = 1;
	}
	sprite->tick--;
	return (texture);
}

t_mlx_img	*get_scorched_rot(t_cub3d *game, t_sprite *sprite)
{
	t_mlx_img	*texture;

	if (sprite->tick < 5 * ANIMATION_CICLE)
	{
		game->map->map[(int)sprite->pos.y * \
				game->map->columns + (int)sprite->pos.x] = 'Z';
		sprite->map_obj = 'Z';
		texture = game->texture.scor20;
	}
	else
		sprite->expire = 1;
	sprite->tick++;
	return (texture);
}

t_mlx_img	*get_scorched_texture(t_cub3d *game, t_sprite *sprite)
{
	if (sprite->shot && sprite->alive && sprite->enabled)
		return (get_scorched_shot(game, sprite));
	else if (sprite->alive)
		return (get_scorched_alive(game, sprite));
	else if (sprite->enabled)
		return (get_scorched_dead(game, sprite));
	else
		return (get_scorched_rot(game, sprite));
	return (game->texture.scor02);
}
