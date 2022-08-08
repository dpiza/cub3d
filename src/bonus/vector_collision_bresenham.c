/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_collision_bresenham.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:26:00 by hde-camp          #+#    #+#             */
/*   Updated: 2022/08/07 20:41:17 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	put_image_pixel(t_mlx_img *img, int x, int y, unsigned int color)
{
	unsigned int	*pixel;

	if (x < img->width && y < img->height && x >= 0 && y >= 0)
	{
		pixel = get_pixel_address(img, x, y);
		*pixel = color;
	}
}

void	start_variables(t_int_point	*sxy, t_int_point	*delta, \
	t_int_point *src, t_int_point *dst)
{
	delta->x = abs(dst->x - src->x);
	delta->y = -abs(dst->y - src->y);
	sxy->x = -1;
	sxy->y = -1;
	if (src->x < dst->x)
		sxy->x = 1;
	if (src->y < dst->y)
		sxy->y = 1;
}

void	bresenham_line(t_mlx_img *img, t_int_point src, \
	t_int_point dst, unsigned int color)
{
	t_int_point	s;
	t_int_point	delta;
	int			err;
	int			e2;

	start_variables(&s, &delta, &src, &dst);
	err = delta.x + delta.y;
	while (1)
	{
		put_image_pixel(img, src.x, src.y, color);
		if (src.x == dst.x && src.y == dst.y)
			break ;
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
