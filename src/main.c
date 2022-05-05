/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:48:44 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/05 18:06:52 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	mlx_test(void)
{
	void	*mlx_connection;
	void	*mlx_window;

	mlx_connection = mlx_init();
	if (mlx_connection)
	{
		mlx_window = mlx_new_window(mlx_connection, 256, 256, "Test Connection");
		sleep(2);
		mlx_clear_window(mlx_connection, mlx_window);
		mlx_destroy_window(mlx_connection, mlx_window);
		mlx_destroy_display(mlx_connection);
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
