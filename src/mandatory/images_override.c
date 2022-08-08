/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_override.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:42:55 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/28 21:12:15 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	override_pixel(char *d, int d_off, char *s, int s_off)
{
	if (*(unsigned int *)(s + s_off) != TRANSPARENCY)
		*(unsigned int *)(d + d_off) = *(unsigned int *)(s + s_off);
}

void	override_images(t_mlx_img *dst, t_mlx_img *src, int x, int y)
{
	char	*dst_pix;
	char	*src_pix;
	int		i_x[2];
	int		i_y[2];
	int		dst_max_size;

	dst_pix = dst->data;
	src_pix = src->data;
	dst_max_size = get_byte_offset(src, dst->width, dst->height);
	i_y[0] = 0;
	while (i_y[0] < src->height)
	{
		i_x[0] = 0;
		while (i_x[0] < src->width)
		{
			i_x[1] = i_x[0] + x;
			i_y[1] = i_y[0] + y;
			if (get_byte_offset(src, i_x[1], i_y[1]) < dst_max_size)
				override_pixel(dst_pix, get_byte_offset(dst, i_x[1], i_y[1]), \
					src_pix, get_byte_offset(src, i_x[0], i_y[0]));
			i_x[0]++;
		}
		i_y[0]++;
	}
}

void	override_mm_pixel(char *d, int d_off, char *s, int s_off)
{
	unsigned int	src_color;
	unsigned int	dst_color;

	dst_color = *(unsigned int *)(d + d_off);
	src_color = *(unsigned int *)(s + s_off);
	if (src_color == (int)MM_FLOOR || src_color == 0U)
		src_color = dst_color;
	if (dst_color == (int)SHADOW && src_color == (int)MM_WALL)
		src_color = (int)MM_WALL_SHADOW;
	if (dst_color == (int)SHADOW && src_color == (int)MM_FLOOR)
		src_color = (int)MM_FLOOR_SHADOW;
	if (dst_color == (int)SHADOW && src_color == (int)PLAYER_RAYS)
		src_color = (int)PLAYER_RAYS_SHADOW;
	*(unsigned int *)(d + d_off) = src_color;
}

void	override_minimap(t_mlx_img *dst, t_mlx_img *src, int x, int y)
{
	char			*dst_p;
	char			*src_p;
	int				i_x[2];
	int				i_y[2];
	int				dst_max_size;

	dst_p = dst->data;
	src_p = src->data;
	dst_max_size = get_byte_offset(src, dst->width, dst->height);
	i_y[0] = 0;
	while (i_y[0] < src->height)
	{
		i_x[0] = 0;
		while (i_x[0] < src->width)
		{
			i_x[1] = i_x[0] + x;
			i_y[1] = i_y[0] + y;
			if (get_byte_offset(src, i_x[1], i_y[1]) < dst_max_size)
				override_mm_pixel(dst_p, get_byte_offset(dst, i_x[1], i_y[1]), \
						src_p, get_byte_offset(src, i_x[0], i_y[0]));
			i_x[0]++;
		}
		i_y[0]++;
	}
}
