/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:48:44 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/28 20:05:03 by dpiza            ###   ########.fr       */
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
	destroy_img(game->crosshair);
	destroy_img(game->weapon);
	destroy_img(game->weapon_fire);
	destroy_img(game->bar);
	destroy_img(game->projection);
	mlx_disconnect(mlx);
	free(mlx);
	destroy_strmap(game->map);
	free(game);
}

void	print_stats(t_cub3d *game)
{
	char	*hp;
	char	*ammo;

	hp = ft_itoa(100);
	ammo = ft_itoa(game->player.ammo);
	mlx_string_put(game->mlx->mlx_ptr, game->mlx->win_ptr, 602, 538, 0x00746736, hp);
	mlx_string_put(game->mlx->mlx_ptr, game->mlx->win_ptr, 605, 583, 0x00746736, ammo);
	free(hp);
	free(ammo);
}

int		game_loop(t_cub3d *game)
{
	build_map(game);
	print_player_int_map(game);
	build_projection(game);
	print_bar_screen(game);
	print_map(game);
	print_projection(game);
	print_weapon(game);
	print_bar(game);
	print_crosshair(game);
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr, game->mlx->img->img_ptr, 0, 0);
	print_stats(game);
	game->tick++;
	return (0);
}

void	mlx_test(t_cub3d	*game)
{
	t_mlx_img	*mlx_img;

	if (game)
	{
		game->mlx->win_ptr = mlx_new_window(game->mlx->mlx_ptr, w_width, w_height, "Nuk3d");
		mlx_img = new_blank_img(game->mlx, w_width, w_height);
		game->mlx->img = mlx_img;
		mlx_hook(game->mlx->win_ptr, 17, 0L, mlx_loop_end, game->mlx->mlx_ptr); // fecha no X
		mlx_hook(game->mlx->win_ptr, 2, 1L << 0, key_hook, game);
		// mlx_hook(game->mlx->win_ptr, 4, 1L << 2, mouse_press, game);
		mlx_hook(game->mlx->win_ptr, 5, 1L << 3, mouse_release, game);
		mlx_hook(game->mlx->win_ptr, 6, 1L << 6, mouse_movement_hook, game);
		mlx_mouse_hook(game->mlx->win_ptr, mouse_hook, game);
		mlx_loop_hook(game->mlx->mlx_ptr, game_loop, game); 
		// game_loop(game); // usado no lugar do loop pra ver o ponto de colisão individualmente
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
	// map = load_map("./maps/huge_map.cub");
	// map = load_map("./maps/subject_map.cub");
	map = load_map("./maps/vault_map.cub");
	eval_map(map);
	if (map->status == OK)
	{
		game = load_game(map);
		if (game)
			mlx_test(game);
	}
	free_t_map(map);
	return (0);
}
