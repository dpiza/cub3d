/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_projection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:11:45 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/24 11:38:37 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

unsigned int	get_texture_pixel(t_mlx_img *img, float column, int line)
{
	unsigned int	*pixel;
	int				texture_x;

	pixel = img->data;
	texture_x = (int)((int)(64 * column) % 64);
	pixel += (unsigned int)texture_x + (int)((float)(line / 100.00) * 64) * 64;
	return (*pixel);
}

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
	int				wall_top;
	int				y_px;

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
		wall_top = height_relation - wall_height;
		while(line < game->projection->height)
		{
			pixel = get_pixel_addres(game->projection, column, line);
			if (line < height_relation && line < height_relation - wall_height)
				*pixel = game->ceiling; // teto
			else if (line > height_relation && line > height_relation + wall_height)
				*pixel = game->floor; // chão
			else
			{
				// *pixel = 0x00000053;
				y_px = (line - wall_top) / (wall_height * 2) * 100;
				if(game->player.collisions[ray].side)
				{
					*pixel = get_texture_pixel(game->texture_no, game->player.collisions[ray].point.y - (int)game->player.collisions[ray].point.y, y_px);
					// *pixel = 0x000000a8;
				}
				else
					*pixel = get_texture_pixel(game->texture_ea, game->player.collisions[ray].point.x - (int)game->player.collisions[ray].point.x, y_px);

			}
			line++;
		}
		column++;
	}
}

void	print_projection(t_cub3d *game)
{
	override_images(game->mlx->img, game->projection, 0, 0);
	// print_texture(game);
}