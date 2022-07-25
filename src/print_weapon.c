/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_weapon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 00:16:59 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/25 10:21:02 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	print_weapon(t_cub3d *game)
{
	override_images_bg(game->mlx->img, game->weapon, w_width / 2 + 30, w_height - 126 - game->weapon->height, TRANSPARENCY);
}

void	print_crosshair(t_cub3d *game)
{
	override_images_bg(game->mlx->img, game->crosshair, (w_width / 2) - game->crosshair->width / 2, (w_height * (1 - 0.2) / 2) - game->crosshair->height / 2, TRANSPARENCY);
}