/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_weapon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 00:16:59 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/28 11:17:53 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	print_weapon(t_cub3d *game)
{
	if (game->player.firing > 0)
	{
		override_images(game->mlx->img, game->weapon_fire, \
			w_width / 2 + 20, w_height - 146 - game->weapon->height);
		game->player.firing++;
		if (game->player.firing > 7)
			game->player.firing = -12;
	}
	else
		override_images(game->mlx->img, game->weapon, \
			w_width / 2 + 30, w_height - 126 - game->weapon->height);
	if (game->player.firing < 0)
		game->player.firing++;
}

void	print_crosshair(t_cub3d *game)
{
	override_images(game->mlx->img, game->crosshair, \
	(w_width / 2) - game->crosshair->width / 2, \
	(w_height * (1 - 0.2) / 2) - game->crosshair->height / 2);
}
