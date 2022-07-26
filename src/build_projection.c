/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_projection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:11:45 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/26 17:59:15 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

unsigned int	get_texture_pixel(t_mlx_img *img, float column, float line)
{
	unsigned int	*pixel;
	int				texture_x;

	pixel = img->data;
	texture_x = (int)(64 * column);
	pixel += (unsigned int)texture_x + (int)(line * 64) * 64;
	return (*pixel);
}

void	build_projection_two(t_cub3d *game)
{
	float			wall_height;
	int				default_wall_height;
	int				wall_start_pos;
	int				line;
	int				column;
	unsigned int	*pixel;

	default_wall_height = (w_height * (1.0 - 0.2)) / 2;
	column = 0;
	while (column < game->projection->width)
	{
		line = 0;
		wall_height = default_wall_height / game->player.collisions[column].perpDistance;
		wall_start_pos = (game->projection->height - wall_height) / 2;
		while (line < wall_start_pos)
		{
			pixel = get_pixel_addres(game->projection, column, line);
			*pixel = game->ceilling;
			line++;
		}
		//while (line < wall_start_pos + wall_height)
		//{
		//	pixel = get_pixel_addres(game->projection, column, line);
		//	*pixel = 255;
		//	line++;
		//}
		while (line < game->projection->height)
		{
			pixel = get_pixel_addres(game->projection, column, line);
			*pixel = game->floor;
			line++;
		}
		column++;
	}
}

void	build_projection(t_cub3d *game)
{
	int				column;
	int				line;
	unsigned int	*pixel;
	t_mlx_img		*texture;
	int				height_relation;
	float			wall_height;
	int				wall_top;
	float			y_px;

	height_relation = (w_height * (1.0 - 0.2)) / 2; //240
	column = 0;
	while(column < game->projection->width)
	{
		line = 0;
		wall_height = height_relation / game->player.collisions[column].perpDistance;
		if (game->player.collisions[column].perpDistance == 1)
			 	pixel = NULL;
		wall_top = height_relation - wall_height;
		while(line < game->projection->height)
		{

			pixel = get_pixel_addres(game->projection, column, line);
			if (line < height_relation && line < height_relation - wall_height)
			 	*pixel = game->ceilling;
			else if (line > height_relation && line > height_relation + wall_height)
				*pixel = game->floor;
			else
			{
				y_px = (line - wall_top) / (wall_height * 2);
				if(game->player.collisions[column].side == NORTH || game->player.collisions[column].side == SOUTH)
				{
					if(game->player.collisions[column].side == NORTH)
						texture = game->texture_no;
					else
						texture = game->texture_so;
					*pixel = get_texture_pixel(texture, game->player.collisions[column].point.x - (int)game->player.collisions[column].point.x, y_px);
				}
				else
				{
					if(game->player.collisions[column].side == EAST)
						texture = game->texture_ea;
					else
						texture = game->texture_we;
					*pixel = get_texture_pixel(texture, game->player.collisions[column].point.y - (int)game->player.collisions[column].point.y, y_px);
				}
				color_shade(game->player.collisions[column].perpDistance, pixel);
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