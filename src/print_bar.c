/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:42:40 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/27 18:58:28 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	print_bar_screen(t_cub3d *game)
{
	int	dst_y;

	dst_y = w_height - game->bar_screen->height;
	override_images(game->mlx->img, game->bar_screen, 0, dst_y);
}

void	print_bar(t_cub3d *game)
{
	int	dst_y;

	dst_y = w_height - game->bar->height;
	override_images_bg(game->mlx->img, game->bar, 0, dst_y, TRANSPARENCY);
}
