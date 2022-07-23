/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_plot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:26:00 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/23 16:55:23 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	put_image_pixel(t_mlx_img *img, int x, int y, unsigned int color)
{
	unsigned int *pixel;

	if (x < img->width && y < img->height && x >= 0 && y >= 0)
	{
		pixel = get_pixel_addres(img, x, y);
		*pixel = color;
	}
}

void	bresenham_line(t_mlx_img *img, int x0, int y0, int x1, int y1, unsigned int color)
{
	int sx;
	int sy;
	int dx;
	int dy;
	int err;
	int e2;

	dx = abs(x1 - x0);
	sx = x0 < x1 ? 1 : -1;
	dy = -abs(y1 - y0);
	sy = y0 < y1 ? 1 : -1;
	err = dx + dy;
	while (1)
	{
		put_image_pixel(img, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}
