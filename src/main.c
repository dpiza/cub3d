/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:48:44 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/10 18:42:07 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

#define	w_height 1024
#define	w_width 1024

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

int		get_pixels_per_square(t_strmap	*map, int max_width, int max_height)
{
	int	n;
	int	l;

	n = map->columns;
	if (map->lines > n)
		n = map->lines;
	l = max_width;
	if (max_height > l)
		l = max_height;
	return (l / n);
}

void	print_square(t_mlx_img	*img, unsigned int *dest_origin, int sqr_size, unsigned int color)
{
	unsigned int	*dest;
	int	i[2];

	dest = dest_origin;
	i[0] = 0;
	while (i[0] < sqr_size)
	{
		i[1] = 0;
		while (i[1] < sqr_size)
		{
			*dest = color;
			dest++;
			i[1]++;
		}
		dest += img->width - sqr_size;
		i[0]++;
	}
}

void	print_map(t_cub3d *game)
{
	int	pps; //pixel per square
	int	line;
	int	square;
	int	pos;
	int	data_pos;

	pps = get_pixels_per_square(game->map, w_width / 2 , w_height / 2);
	if (pps)
	{
		line = 0;
		while (line < game->map->lines)
		{
			square = 0;
			while (square < game->map->columns)
			{
				pos = line * game->map->columns + square;
				data_pos = square * pps + (pps * game->mlx->img->width * line);
				if ((char)game->map->map[pos] == ' ')
					print_square(game->mlx->img, &((unsigned int *)game->mlx->img->data)[data_pos], pps, 0x00ffffff);
				else if((char)game->map->map[pos] == '1')
					print_square(game->mlx->img, &((unsigned int *)game->mlx->img->data)[data_pos], pps, 0x009c000d);
				else if((char)game->map->map[pos] == '0')
					print_square(game->mlx->img, &((unsigned int *)game->mlx->img->data)[data_pos], pps, 0x00ff924f);
				else
					print_square(game->mlx->img, &((unsigned int *)game->mlx->img->data)[data_pos], pps, 0x0007e637);
				square++;
			}
			line++;
		}
	}
}

void	mlx_test(t_cub3d	*game)
{
	//t_mlx		*mlx;
	t_mlx_img	*mlx_img;

	//mlx = ft_calloc(1, sizeof(t_mlx));
	//mlx->mlx_ptr = mlx_init();
	//if (mlx->mlx_ptr)
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
		game = ft_calloc(1, sizeof(t_cub3d));
		game->map = new_strmap();
		load_strmap(game->map, map);
		mlx_test(game);
	}
	free_t_map(map);
	return (0);
}
