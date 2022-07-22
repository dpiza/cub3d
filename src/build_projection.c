/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_projection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:11:45 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/22 13:55:27 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	build_projection(t_cub3d *game)
{
	int	col;
	int	lines;
	unsigned int *pixel;
	t_mlx_img	*projection;
	
	
	projection = new_blank_img(game->mlx, w_width, w_height * 0.8);
	game->projection = projection;
	printf("Width: %i\nHeight: %i\n", projection->width, projection->height);
	lines = 0;
	while(lines < game->projection->height)
	{
		col = 0;
		while(col < game->projection->width)
		{
			pixel = get_pixel_addres(game->projection, col, lines);
			*pixel = 0x808080;
			col++;
		}
		lines++;
	}
}

void	print_projection(t_cub3d *game)
{
	override_images(game->mlx->img, game->projection, 0, 0);
}