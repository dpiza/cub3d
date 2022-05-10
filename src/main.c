/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:48:44 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/10 11:53:58 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	mlx_test(void)
{
	t_mlx		*mlx;
	t_mlx_img	mlx_img;
	t_mlx_img	*blank_img;
	char		*path = "./textures/no.xpm";

	mlx = ft_calloc(1, sizeof(t_mlx));
	mlx->connection = mlx_init();
	if (mlx->connection)
	{

		ft_bzero(&mlx_img, sizeof(t_mlx_img));
		blank_img = ft_calloc(1, sizeof(t_mlx_img));
		mlx->window = mlx_new_window(mlx->connection, 512, 512, "Test Connection");
		mlx_img.addr = mlx_xpm_file_to_image(mlx->connection, path, &mlx_img.width, &mlx_img.height);
		mlx_img.data_addr = mlx_get_data_addr(&mlx_img.addr, &mlx_img.bpp, &mlx_img.line_size, &mlx_img.endian);
		blank_img->addr = mlx_new_image(mlx->connection, 100, 100);
		blank_img->data_addr = mlx_get_data_addr(mlx->connection, &(blank_img->bpp), &(blank_img->line_size), &(blank_img->endian));
		
		mlx_put_image_to_window(mlx->connection, mlx->window, mlx_img.addr, 0, 0);
		mlx_hook(mlx->window, 2, 1L << 0, key_hook, mlx);
		mlx_loop(mlx->connection);
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
