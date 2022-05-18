/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   override_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:42:55 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/18 18:43:14 by hde-camp         ###   ########.fr       */
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
			*(unsigned int *)(dst_pix + get_byte_offset(dst, i_x[1], i_y[1])) = \
			*(unsigned int *)(src_pix + get_byte_offset(src, i_x[0], i_y[0]));
			i_x[0]++;
		}
		i_y[0]++;
	}
}
