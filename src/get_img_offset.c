/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img_offset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:03:26 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/11 16:25:33 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	*get_pixel_addres(t_mlx_img	*img, int x, int y)
{
	char *pos;

	pos = (char *)img->data;
	pos += get_byte_offset(img, x, y);
	return (pos);
}

int	get_byte_offset(t_mlx_img	*img, int x, int y)
{
	return (y * img->line_size + x * (img->bpp / 8));
}
