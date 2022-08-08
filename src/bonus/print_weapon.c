/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_weapon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 00:16:59 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/07 20:41:00 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	print_weapon(t_cub3d *game)
{
	if (game->player.firing > 0)
	{
		override_images(game->mlx->img, game->texture.weapon_fire, \
			W_WIDTH / 2 + 20, W_HEIGHT - 146 - game->texture.weapon->height);
		game->player.firing++;
		if (game->player.firing > ANIMATION_CICLE)
			game->player.firing = -ANIMATION_CICLE;
	}
	else
		override_images(game->mlx->img, game->texture.weapon, \
			W_WIDTH / 2 + 30, W_HEIGHT - 126 - game->texture.weapon->height);
	if (game->player.firing < 0)
		game->player.firing++;
}

void	print_crosshair(t_cub3d *game)
{
	override_images(game->mlx->img, game->texture.crosshair, \
	400 - game->texture.crosshair->width / 2, \
	240 - game->texture.crosshair->height / 2);
}

void	print_notification(t_cub3d *game)
{
	t_int_point	point;

	point.y = 10;
	point.x = 10;
	if (game->player.notify > 0 && game->player.notify <= 150)
	{
		override_images(game->mlx->img, game->texture.notif_key, \
			point.x, point.y);
		game->player.notify++;
		if (game->player.notify > 150)
			game->player.notify = 0;
	}
	else if (game->player.notify > 150)
	{
		override_images(game->mlx->img, game->texture.notif_door, \
			point.x, point.y);
		game->player.notify++;
		if (game->player.notify > 300)
			game->player.notify = 0;
	}
}

void	print_damage(t_cub3d *game)
{
	if (game->player.damaged > 0)
	{
		override_images(game->mlx->img, game->texture.dmg, 0, 0);
		override_images(game->mlx->img, game->texture.dmg, 799, 0);
		game->player.damaged--;
	}
}
