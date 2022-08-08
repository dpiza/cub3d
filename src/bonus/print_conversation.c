/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:29:34 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/07 20:40:29 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	print_conversation(t_cub3d *game)
{
	t_int_point	point;

	point.y = W_HEIGHT - game->texture.conversation->height;
	point.x = 0;
	flickering(game, &point);
	if (game->player.in_conversation && game->player.aimed_obj == 'C')
		override_images(game->mlx->img, game->texture.conversation, \
			point.x, point.y);
}
