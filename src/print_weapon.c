/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_weapon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 00:16:59 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/24 00:24:17 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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

void	print_weapon(t_cub3d *game)
{
	t_mlx_img	*img;
	int			width;
	int			height;
	
	width = 98;
	height = 164;
	img = ft_calloc(1, sizeof(t_mlx_img));
	img->mlx = game->mlx;
	img->img_ptr = mlx_xpm_file_to_image(game->mlx->mlx_ptr, "./textures/weapon_bg.xpm", &width, &height);
	img->data = mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->line_size), &(img->endian));
	img->width = width;
	img->height = height;
	override_images_bg(game->mlx->img, img, w_width / 2, w_height - 126 - height, 15404543);
}