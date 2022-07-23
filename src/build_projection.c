/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_projection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:11:45 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/22 22:52:41 by dpiza            ###   ########.fr       */
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
	
	projection = new_blank_img(game->mlx, w_width,(int)(w_height * (1.0 - 0.2))); // 0.2 = strMap->XYfactor[1]
	// removi o strMap->XYfactor[1] porque ele está sendo usado pra definir o
	// tamanho do minimap e acaba afetando o tamanho da tela de projeção
	game->projection = projection;
	width_relation = (float)game->player.n_rays / (float)w_width;
	height_relation = (w_height * (1.0 - 0.2)) / 2; // 0.2 = strMap->XYfactor[1]
	column = 0;
	while(column < game->projection->width)
	{
		line = 0;
		ray = column * width_relation;
		wall_height = height_relation / game->player.collisions[ray].perpDistance;
		while(line < game->projection->height)
		{
			pixel = get_pixel_addres(game->projection, column, line);
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
			line++;
		}
		column++;
	}
}

void	print_projection(t_cub3d *game)
{
	override_images(game->mlx->img, game->projection, 0, 0);
}