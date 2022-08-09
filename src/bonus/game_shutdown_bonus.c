/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_shutdown_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:17:18 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/09 17:20:30 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

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

void	destroy_sprites(t_cub3d *game)
{
	t_sprite_list	*current;
	t_sprite_list	*previous;

	current = game->sprite_list;
	previous = NULL;
	while (current)
	{
		free(current->sprite);
		previous = current;
		current = current->next;
		free(previous);
	}
}

void	gracefull_shutdown(t_cub3d	*game)
{
	t_mlx	*mlx;

	mlx = game->mlx;
	free(game->player.rays);
	free(game->player.collisions);
	destroy_textures(game);
	destroy_sprites(game);
	destroy_img(mlx->img);
	destroy_img(game->map->minimap);
	destroy_img(game->projection);
	destroy_img(game->menu_map);
	mlx_disconnect(mlx);
	free(mlx);
	destroy_strmap(game->map);
	free_t_map(game->s_map);
	free(game);
}
