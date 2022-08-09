/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cods_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:46:19 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/07 20:38:04 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

t_mlx_img	*get_cods_texture(t_cub3d *game, t_sprite *sprite)
{
	t_mlx_img	*texture;

	texture = game->texture.cods00;
	if (sprite->tick > 4 * ANIMATION_CICLE)
		sprite->tick = 0;
	if (sprite->tick < 2 * ANIMATION_CICLE)
		texture = game->texture.cods00;
	else if (sprite->tick < 4 * ANIMATION_CICLE)
		texture = game->texture.cods01;
	sprite->tick++;
	return (texture);
}
