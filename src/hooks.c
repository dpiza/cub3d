/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:01:01 by dpiza             #+#    #+#             */
/*   Updated: 2022/05/06 17:18:45 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	winclose(t_mlx *mlx)
{
	mlx_clear_window(mlx->connection, mlx->window);
	mlx_destroy_window(mlx->connection, mlx->window);
	mlx_destroy_display(mlx->connection);
	exit (0);
}

int	key_hook(int k, t_mlx *mlx)
{
	if (k == 65307) // ESC
		winclose(mlx);
	return (0);
}