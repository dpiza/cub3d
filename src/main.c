/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:48:44 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/10 14:22:35 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

#define	w_height 512
#define	w_width 512

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

void	gracefull_shutdown(t_mlx *mlx)
{
	destroy_img(mlx->img);
	mlx_disconnect(mlx);
	free(mlx);
}

void	mlx_test(void)
{
	t_mlx		*mlx;
	t_mlx_img	*mlx_img;

	mlx = ft_calloc(1, sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr)
	{
		mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, w_width, w_height, "Test Window");
		mlx_img = new_blank_img(mlx, 100, 100);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx_img->img_ptr, 0, 0);
		mlx_hook(mlx->win_ptr, 2, 1L << 0, key_hook, mlx);
		//mlx_loop(mlx->mlx_ptr);
		printf("Before\n");
		sleep(1);
		printf("After\n");
		gracefull_shutdown(mlx);
	}
}

int	main(int argc, char *argv[])
{
	t_map	*map;

	(void)argc;
	(void)argv;
	map = load_map("./maps/subject_map.cub");
	eval_map(map);
	if (map->status == OK)
	{
		printf("Map is ok\n");
		mlx_test();
	}
	free_t_map(map);
	return (0);
}
