/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:01:01 by dpiza             #+#    #+#             */
/*   Updated: 2022/05/09 22:45:00 by hde-camp         ###   ########.fr       */
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
	if (k == 0xff1b) // ESC
		winclose(mlx);
	if (k == 0x0061 || k == 0x0041)
		printf("a pressed\n");
	if (k == 0x0073 || k == 0x0053)
		printf("s pressed\n");
	if (k == 0x0064 || k == 0x0044)
		printf("d pressed\n");
	if (k == 0x0077 || k == 0x0057)
		printf("w pressed\n");
	if (k == 0x0070 || k == 0x0050)
		printf("p pressed\n");
	if (k == 0xff0d)
		printf("return pressed\n");
	/*
	teclas de interesse:
				normal		UPPERCASE
	a			0x0061		0x0041
	s			0x0073		0x0053
	d			0x0064		0x0044
	w			0x0077		0x0057
	p			0x0070		0x0050
	escape		0xff1b
	enter		0xff0d
	uparrow		0xff52
	downarrow	0xff54
	leftarrow	0xff51
	rightarrow	0xff53
	*/
	return (0);
}