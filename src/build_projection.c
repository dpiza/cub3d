/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_projection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:11:45 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/22 21:00:30 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	build_projection(t_cub3d *game)
{
	int				column;
	int				line;
	unsigned int	*pixel;
	t_mlx_img		*projection;
	int				ray;
	float			width_relation;
	float			height_relation;
	float			wall_height;
	
	projection = new_blank_img(game->mlx, w_width,(int)(w_height * (1.0 - game->map->XYfactor[1])));
	game->projection = projection;
	width_relation = (float)game->player.n_rays / (float)w_width;
	height_relation = (w_height * (1.0 - game->map->XYfactor[1])) / 2;
	line = 0;
	while(line < game->projection->height)
	{
		column = 0;
		while(column < game->projection->width)
		{
			pixel = get_pixel_addres(game->projection, column, line);
			ray = column * width_relation;
			wall_height = height_relation / game->player.collisions[ray].perpDistance;
			if (line < height_relation && line < height_relation - wall_height)
				*pixel = 0x00383838;
			else if (line > height_relation && line > wall_height + height_relation)
				*pixel = 0x00717171;
			else
			{
				*pixel = 0x00000053;
				if(game->player.collisions[ray].side)
					*pixel = 0x000000a8;
			}
			column++;
		}
		line++;
	}
}

void	print_projection(t_cub3d *game)
{
	override_images(game->mlx->img, game->projection, 0, 0);
}