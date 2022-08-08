/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 01:48:42 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/07 20:37:47 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	stand_by(t_cub3d *game)
{
	game->tick = 0;
	override_images(game->mlx->img, game->texture.standby, 0, 0);
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr, \
		game->mlx->img->img_ptr, 0, 0);
}

void	game_over(t_cub3d *game)
{
	mlx_string_put(game->mlx->mlx_ptr, game->mlx->win_ptr, \
		325, 220, 0x003cf800, "Thank you for playing Nuk3d!");
}
