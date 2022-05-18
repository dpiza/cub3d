/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:48:44 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/18 17:28:43 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	destroy_img(t_mlx_img *mlx_img)
{
	mlx_destroy_image(mlx_img->mlx->mlx_ptr,	mlx_img->img_ptr);
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
	destroy_img(mlx->img);
	mlx_disconnect(mlx);
	free(mlx);
	destroy_strmap(game->map);
	free(game);
}

void	mlx_test(t_cub3d	*game)
{
	t_mlx_img	*mlx_img;

	if (init_game_state(game))
	{
		game->mlx->win_ptr = mlx_new_window(game->mlx->mlx_ptr, w_width, w_height, "Test Window");
		mlx_img = new_blank_img(game->mlx, w_width, w_height);
		game->mlx->img = mlx_img;
		print_map(game);
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr, mlx_img->img_ptr, 0, 0);
		print_player_int_map(game);
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr, mlx_img->img_ptr, 0, 0);
		mlx_hook(game->mlx->win_ptr, 2, 1L << 0, key_hook, game);
		mlx_loop(game->mlx->mlx_ptr);
		gracefull_shutdown(game);
	}
}

int	main(int argc, char *argv[])
{
	t_map	*map;
	t_cub3d	*game;

	(void)argc;
	(void)argv;
	map = load_map("./maps/subject_map.cub");
	eval_map(map);
	if (map->status == OK)
	{
		game = load_game(map);
		mlx_test(game);
	}
	free_t_map(map);
	return (0);
}
