/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_weapon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 00:16:59 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/24 09:28:31 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
	override_images_bg(game->mlx->img, img, w_width / 2, w_height - 126 - height, (unsigned int)0x00EB0DFF);
}