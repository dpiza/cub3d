/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:42:40 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/23 23:54:38 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	print_border(t_cub3d *game)
{
	t_mlx_img	*img;
	int			width;
	int			height;
	
	width = 27;
	height = 126;
	img = ft_calloc(1, sizeof(t_mlx_img));
	img->mlx = game->mlx;
	img->img_ptr = mlx_xpm_file_to_image(game->mlx->mlx_ptr, "./textures/bar/fo_bar_01.xpm", &width, &height);
	img->data = mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->line_size), &(img->endian));
	img->width = width;
	img->height = height;
	override_images(game->mlx->img, img, 0, w_height - height);
}

void	print_upper(t_cub3d *game)
{
	t_mlx_img	*img;
	int			width;
	int			height;
	
	width = 209;
	height = 28;
	img = ft_calloc(1, sizeof(t_mlx_img));
	img->mlx = game->mlx;
	img->img_ptr = mlx_xpm_file_to_image(game->mlx->mlx_ptr, "./textures/bar/fo_bar_02.xpm", &width, &height);
	img->data = mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->line_size), &(img->endian));
	img->width = width;
	img->height = height;
	override_images(game->mlx->img, img, 27, w_height - 126);
}

void	print_lower(t_cub3d *game)
{
	t_mlx_img	*img;
	int			width;
	int			height;
	
	width = 209;
	height = 25;
	img = ft_calloc(1, sizeof(t_mlx_img));
	img->mlx = game->mlx;
	img->img_ptr = mlx_xpm_file_to_image(game->mlx->mlx_ptr, "./textures/bar/fo_bar_03.xpm", &width, &height);
	img->data = mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->line_size), &(img->endian));
	img->width = width;
	img->height = height;
	override_images(game->mlx->img, img, 27, w_height - height);
}

void	print_right(t_cub3d *game)
{
	t_mlx_img	*img;
	int			width;
	int			height;
	
	width = 564;
	height = 126;
	img = ft_calloc(1, sizeof(t_mlx_img));
	img->mlx = game->mlx;
	img->img_ptr = mlx_xpm_file_to_image(game->mlx->mlx_ptr, "./textures/bar/fo_bar_04.xpm", &width, &height);
	img->data = mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->line_size), &(img->endian));
	img->width = width;
	img->height = height;
	override_images(game->mlx->img, img, 236, w_height - height);
}

void	print_bar(t_cub3d *game)
{
	print_border(game);
	print_upper(game);
	print_lower(game);
	print_right(game);
}

void	clear_map(t_cub3d *game)
{
	t_mlx_img	*img;
	int			width;
	int			height;
	
	width = 255;
	height = 126;
	img = ft_calloc(1, sizeof(t_mlx_img));
	img->mlx = game->mlx;
	img->img_ptr = mlx_xpm_file_to_image(game->mlx->mlx_ptr, "./textures/bar/fo_bar_05.xpm", &width, &height);
	img->data = mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->line_size), &(img->endian));
	img->width = width;
	img->height = height;
	override_images(game->mlx->img, img, 0, w_height - height);
}