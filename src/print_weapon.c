/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_weapon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 00:16:59 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/26 23:06:52 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	print_weapon(t_cub3d *game)
{
	if(game->player.state > 0)
	{
		override_images_bg(game->mlx->img, game->weapon_fire, w_width / 2 + 20, w_height - 146 - game->weapon->height, TRANSPARENCY);
		game->player.state++;
		if (game->player.state > 7)
			game->player.state = 0;
	}
	else
		override_images_bg(game->mlx->img, game->weapon, w_width / 2 + 30, w_height - 126 - game->weapon->height, TRANSPARENCY);
}

void	print_crosshair(t_cub3d *game)
{
	override_images_bg(game->mlx->img, game->crosshair, (w_width / 2) - game->crosshair->width / 2, (w_height * (1 - 0.2) / 2) - game->crosshair->height / 2, TRANSPARENCY);
}