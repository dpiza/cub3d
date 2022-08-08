/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_shutdown.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:17:18 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/08 12:53:24 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	destroy_img(t_mlx_img *mlx_img)
{
	mlx_destroy_image(mlx_img->mlx->mlx_ptr, mlx_img->img_ptr);
	free(mlx_img);
}

void	mlx_disconnect(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
}

void	gracefull_shutdown(t_cub3d	*game)
{
	t_mlx	*mlx;

	mlx = game->mlx;
	free(game->player.rays);
	free(game->player.collisions);
	destroy_img(mlx->img);
	destroy_img(game->map->minimap);
	destroy_img(game->texture_no);
	destroy_img(game->texture_so);
	destroy_img(game->texture_we);
	destroy_img(game->texture_ea);
	destroy_img(game->bar_screen);
	destroy_img(game->bar);
	destroy_img(game->projection);
	mlx_disconnect(mlx);
	free(mlx);
	destroy_strmap(game->map);
	free(game);
}
