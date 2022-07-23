/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:42:40 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/22 22:44:43 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	print_bar(t_cub3d *game)
{
	t_mlx_img	*img;
	int			width = 800;
	int			height = 126;
	
	img = ft_calloc(1, sizeof(t_mlx_img));
	img->mlx = game->mlx;
	img->img_ptr = mlx_xpm_file_to_image(game->mlx->mlx_ptr, "./textures/fo_bar.xpm", &width, &height);
	img->data = mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->line_size), &(img->endian));
	img->width = width;
	img->height = height;
	override_images(game->mlx->img, img, 0, w_height - height);
}
