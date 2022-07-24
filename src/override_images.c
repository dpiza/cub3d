/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   override_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:42:55 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/24 11:16:19 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	override_images(t_mlx_img *dst, t_mlx_img *src, int x, int y)
{
	char	*dst_pix;
	char	*src_pix;
	int		i_x[2];
	int		i_y[2];

	dst_pix = dst->data;
	src_pix = src->data;
	i_y[0] = 0;
	while (i_y[0] < src->height)
	{
		i_x[0] = 0;
		while (i_x[0] < src->width)
		{
			i_x[1] = i_x[0] + x;
			i_y[1] = i_y[0] + y;
			if (get_byte_offset(src, i_x[1], i_y[1]) < get_byte_offset(src, dst->width, dst->height))
			{
				*(unsigned int *)(dst_pix + get_byte_offset(dst, i_x[1], i_y[1])) = \
				*(unsigned int *)(src_pix + get_byte_offset(src, i_x[0], i_y[0]));
			}
			i_x[0]++;
		}
		i_y[0]++;
	}
}

void	override_minimap(t_mlx_img *dst, t_mlx_img *src, int x, int y)
{
	char			*dst_pix;
	char			*src_pix;
	unsigned int	src_color;
	unsigned int	dst_color;
	int				i_x[2];
	int				i_y[2];

	dst_pix = dst->data;
	src_pix = src->data;
	i_y[0] = 0;
	while (i_y[0] < src->height)
	{
		i_x[0] = 0;
		while (i_x[0] < src->width)
		{
			i_x[1] = i_x[0] + x;
			i_y[1] = i_y[0] + y;
			if (get_byte_offset(src, i_x[1], i_y[1]) < get_byte_offset(src, dst->width, dst->height))
			{
				dst_color = *(unsigned int *)(dst_pix + get_byte_offset(dst, i_x[1], i_y[1]));
				src_color = *(unsigned int *)(src_pix + get_byte_offset(src, i_x[0], i_y[0]));
				if (dst_color == (int)shadow && src_color == (int)mm_wall)
					src_color = (int)mm_wall_shadow;
				if (dst_color == (int)shadow && src_color == (int)mm_floor)
					src_color = (int)mm_floor_shadow;
				if (dst_color == (int)shadow && src_color == (int)player_rays)
					src_color = (int)player_rays_shadow;
				*(unsigned int *)(dst_pix + get_byte_offset(dst, i_x[1], i_y[1])) = src_color;
			}
			i_x[0]++;
		}
		i_y[0]++;
	}
}

void	override_images_bg(t_mlx_img *dst, t_mlx_img *src, int x, int y, unsigned int bg)
{
	char	*dst_pix;
	char	*src_pix;
	int		i_x[2];
	int		i_y[2];

	dst_pix = dst->data;
	src_pix = src->data;
	i_y[0] = 0;
	while (i_y[0] < src->height)
	{
		i_x[0] = 0;
		while (i_x[0] < src->width)
		{
			i_x[1] = i_x[0] + x;
			i_y[1] = i_y[0] + y;
			if (get_byte_offset(src, i_x[1], i_y[1]) < get_byte_offset(src, dst->width, dst->height)
			&& *(unsigned int *)(src_pix + get_byte_offset(src, i_x[0], i_y[0])) != bg)
			{
				*(unsigned int *)(dst_pix + get_byte_offset(dst, i_x[1], i_y[1])) = \
				*(unsigned int *)(src_pix + get_byte_offset(src, i_x[0], i_y[0]));
			}
			i_x[0]++;
		}
		i_y[0]++;
	}
}