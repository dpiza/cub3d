/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:48:44 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/12 23:15:12 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_mlx_img	*new_blank_img(t_mlx	*mlx, int width, int height)
{
	t_mlx_img	*img;

	img = ft_calloc(1, sizeof(t_mlx_img));
	img->mlx = mlx;
	mlx->img = img;
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, width, height);
	img->data = mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->line_size), &(img->endian));
	img->width = width;
	img->height = height;
	return (img);
}

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

int		init_state(t_cub3d *game)
{
	game->mlx = ft_calloc(1, sizeof(t_mlx));
	game->mlx->mlx_ptr = mlx_init();
	if (game->mlx->mlx_ptr)
		return (1);
	return (0);
}

void	mlx_test(t_cub3d	*game)
{
	t_mlx_img	*mlx_img;

	if (init_state(game))
	{
		game->mlx->win_ptr = mlx_new_window(game->mlx->mlx_ptr, w_width, w_height, "Test Window");
		mlx_img = new_blank_img(game->mlx, w_width, w_height);
		print_map(game);
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr, mlx_img->img_ptr, 0, 0);
		mlx_hook(game->mlx->win_ptr, 2, 1L << 0, key_hook, game);
		mlx_loop(game->mlx->mlx_ptr);
		gracefull_shutdown(game);
	}
}

void	set_player_dir(t_player *player, char dir)
{
	if (dir == 'N')
	{
		player->dir.x = 0;
		player->dir.y = -1;
	}
	else if (dir == 'S')
	{
		player->dir.x = 0;
		player->dir.y = 1;
	}
	else if (dir == 'W')
	{
		player->dir.x = -1;
		player->dir.y = 0;
	}
	else if (dir == 'E')
	{
		player->dir.x = 1;
		player->dir.y = 0;
	}
}

void	load_player(t_strmap	*map, t_player	*player)
{
	int		y_max;
	int		x_max;
	int		count;
	char	*map_v;

	y_max = map->lines;
	x_max = map->columns;
	count = 0;
	while (count < y_max * x_max)
	{
		map_v = ft_strchr("NSEW", (int)map->map[count]);
		if (map_v)
		{
			player->pos.x = (count % x_max);
			player->pos.y = (count / y_max);
			set_player_dir(player, (char)map->map[count]);
			break;
		}
		count++;
	}
}

t_cub3d	*load_game(t_map	*map)
{
	t_cub3d		*game;

	game = NULL;
	game = ft_calloc(1, sizeof(t_cub3d));
	if (!game)
		return (NULL);
	game->map = new_strmap();
	load_strmap(game->map, map);
	load_player(game->map, &game->player);
	return (game);
}

int	main(int argc, char *argv[])
{
	t_map	*map;
	t_cub3d	*game;

	(void)argc;
	(void)argv;
	map = load_map("./maps/huge_map.cub");
	eval_map(map);
	if (map->status == OK)
	{
		game = load_game(map);
		//game = ft_calloc(1, sizeof(t_cub3d));
		//game->map = new_strmap();
		//load_strmap(game->map, map);
		mlx_test(game);
	}
	free_t_map(map);
	return (0);
}
