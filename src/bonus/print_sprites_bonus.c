/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 23:06:59 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/07 20:40:49 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	print_sprite_pixel(t_cub3d *game, t_sprite *sprite, t_int_point i)
{
	t_point			relative;
	unsigned int	*pixel;
	unsigned int	sprt_pixel;

	sprt_pixel = 0;
	if (i.y < 0 || i.x < 0 || i.x > W_WIDTH || i.y > 480)
		return ;
	pixel = get_pixel_address(game->projection, i.x, i.y);
	relative.x = (float)(i.x - sprite->render_pos.x) / sprite->width;
	relative.y = (float)(i.y - sprite->render_pos.y) / sprite->height;
	sprt_pixel = get_texture_pixel(sprite->texture, relative.x, relative.y);
	if (sprt_pixel != TRANSPARENCY)
	{
		*pixel = sprt_pixel;
		color_shade(sprite->distance, pixel);
	}
}

void	print_sprite(t_cub3d *game, t_sprite *sprite)
{
	t_int_point	i;

	if (sprite->render_pos.x < -400 || sprite->render_pos.x > 800
		|| sprite->distance > 12 || sprite->distance < 0.25 || sprite->expire)
		return ;
	i.x = sprite->render_pos.x;
	while (i.x < sprite->width + sprite->render_pos.x)
	{
		if (i.x > 0
			&& game->player.collisions[i.x].distance > sprite->distance)
		{
			i.y = sprite->render_pos.y;
			while (i.y < sprite->height + sprite->render_pos.y)
			{
				print_sprite_pixel(game, sprite, i);
				i.y++;
			}
		}
		i.x++;
	}
}

t_mlx_img	*get_sprite_texture(t_cub3d *game, t_sprite *sprite)
{
	if (sprite->map_obj == 'X' || sprite->map_obj == 'Z')
		return (get_scorched_texture(game, sprite));
	if (sprite->map_obj == 'C')
		return (get_cods_texture(game, sprite));
	return (NULL);
}

void	set_sprite_properties(t_cub3d *game, t_sprite *sprite)
{
	t_point	difference;
	float	angle;
	float	screen_angle;

	sprite->texture = get_sprite_texture(game, sprite);
	difference.x = sprite->pos.x - game->player.pos.x;
	difference.y = sprite->pos.y - game->player.pos.y;
	sprite->distance = sqrt(difference.x * difference.x + \
		difference.y * difference.y);
	sprite->height = DEFAULT_HEIGHT / sprite->distance * 0.75;
	sprite->width = sprite->height;
	angle = atan2(-difference.y, difference.x) * TO_DEGREE;
	if (angle > 360)
		angle -= 360;
	if (angle < 0)
		angle += 360;
	screen_angle = game->player.angle + (FOV / 2) - angle;
	if (angle > 270 && game->player.angle < 90)
		screen_angle = game->player.angle + (FOV / 2) - angle + 360;
	if (game->player.angle > 270 && angle < 90)
		screen_angle = game->player.angle + (FOV / 2) - angle - 360;
	sprite->render_pos.x = screen_angle * W_WIDTH / FOV - sprite->width / 2;
	sprite->render_pos.y = DEFAULT_HEIGHT / 2 - sprite->height / 3;
}

void	print_sprite_list(t_cub3d *game)
{
	t_sprite		*sprite;
	t_sprite_list	*current;

	current = game->sprite_list;
	if (!current)
		return ;
	while (current)
	{
		sprite = current->sprite;
		if (!sprite->expire)
			set_sprite_properties(game, sprite);
		print_sprite(game, sprite);
		if (sprite->map_obj == 'X')
		{
			damage_player(game, sprite);
			move_closer(game, sprite);
		}
		set_collisions(game);
		current = current->next;
	}
}
