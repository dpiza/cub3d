/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:48:44 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/06 17:27:38 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	mlx_test(void)
{
	t_mlx	*mlx;
	int		img_width = 0;
	int		img_height = 0;
	char	*path = "./textures/test.xpm";

	mlx = ft_calloc(1, sizeof(t_mlx));
	mlx->connection = mlx_init();
	if (mlx->connection)
	{
		mlx->window = mlx_new_window(mlx->connection, 256, 256, "Test Connection");

		// mlx->img = mlx_new_image(mlx->connection, 256, 256);
		mlx->addr = (int *)mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->ll, &mlx->end);
		// mlx->addr[256*128+128] = 0x00ffffff;
		
		mlx->img = mlx_xpm_file_to_image(mlx->connection, path, &img_width, &img_height);
		
		mlx_put_image_to_window(mlx->connection, mlx->window, mlx->img, 0, 0);
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
