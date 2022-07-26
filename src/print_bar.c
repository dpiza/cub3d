/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:42:40 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/25 21:20:40 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	print_bar_screen(t_cub3d *game)
{
	override_images(game->mlx->img, game->bar_screen, 0, w_height - game->bar_screen->height);
}

void	print_bar(t_cub3d *game)
{
	override_images_bg(game->mlx->img, game->bar, 0, w_height - game->bar->height, TRANSPARENCY);
}