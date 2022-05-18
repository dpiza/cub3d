/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_blank_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:08:00 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/18 17:28:11 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_mlx_img	*new_blank_img(t_mlx	*mlx, int width, int height)
{
	t_mlx_img	*img;

	img = ft_calloc(1, sizeof(t_mlx_img));
	img->mlx = mlx;
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, width, height);
	img->data = mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->line_size), &(img->endian));
	img->width = width;
	img->height = height;
	return (img);
}
