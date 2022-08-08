/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_blank_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:08:00 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/27 18:48:40 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_mlx_img	*new_blank_img(t_mlx *mlx, int width, int height)
{
	t_mlx_img	*img;
	int			*bpp;
	int			*l_size;

	img = ft_calloc(1, sizeof(t_mlx_img));
	img->mlx = mlx;
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, width, height);
	bpp = &(img->bpp);
	l_size = &(img->line_size);
	img->data = mlx_get_data_addr(img->img_ptr, bpp, l_size, &(img->endian));
	img->width = width;
	img->height = height;
	return (img);
}
