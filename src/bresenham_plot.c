/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_plot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:26:00 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/27 17:07:15 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	put_image_pixel(t_mlx_img *img, int x, int y, unsigned int color)
{
	unsigned int	*pixel;

	if (x < img->width && y < img->height && x >= 0 && y >= 0)
	{
		pixel = get_pixel_addres(img, x, y);
		*pixel = color;
	}
}

void	bresenham_line(t_mlx_img *img, t_int_point src, t_int_point dst, unsigned int color)
{
	t_int_point s;
	t_int_point delta;
	int err;
	int e2;

	delta.x = abs(dst.x - src.x);
	s.x = src.x < dst.x ? 1 : -1;
	delta.y = -abs(dst.y - src.y);
	s.y = src.y < dst.y ? 1 : -1;
	err = delta.x + delta.y;
	while (1)
	{
		put_image_pixel(img, src.x, src.y, color);
		if (src.x == dst.x && src.y == dst.y)
			break;
		e2 = 2 * err;
		if (e2 >= delta.y)
		{
			err += delta.y;
			src.x += s.x;
		}
		if (e2 <= delta.x)
		{
			err += delta.x;
			src.y += s.y;
		}
	}
}
