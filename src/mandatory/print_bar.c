/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:42:40 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/28 21:05:20 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	print_bar_screen(t_cub3d *game)
{
	int	dst_y;

	dst_y = W_HEIGHT - game->bar_screen->height;
	override_images(game->mlx->img, game->bar_screen, 0, dst_y);
}

void	print_bar(t_cub3d *game)
{
	int	dst_y;

	dst_y = W_HEIGHT - game->bar->height;
	override_images(game->mlx->img, game->bar, 0, dst_y);
}

void	print_stats(t_cub3d *game)
{
	char	*hp;
	char	*ammo;

	hp = ft_itoa(100);
	ammo = ft_itoa(game->player.ammo);
	mlx_string_put(game->mlx->mlx_ptr, game->mlx->win_ptr, \
		602, 538, 0x00746736, hp);
	mlx_string_put(game->mlx->mlx_ptr, game->mlx->win_ptr, \
		605, 583, 0x00746736, ammo);
	free(hp);
	free(ammo);
}
