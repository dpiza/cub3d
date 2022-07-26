/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_projection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:11:45 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/26 19:31:52 by hde-camp         ###   ########.fr       */
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

t_mlx_img	*get_texture(t_cub3d *game, int side)
{
	if (side == NORTH)
		return (game->texture_no);
	else if (side == SOUTH)
		return (game->texture_so);
	else if (side == EAST)
		return (game->texture_ea);
	else
		return (game->texture_we);
}

int	get_wall_bottom(int	wall_top, int total_height ,float wall_height)
{
	if (wall_height + wall_top > total_height)
		return (total_height);
	return (wall_top + (int)wall_height);
}

void	build_projection_two(t_cub3d *game)
{
	int				column;
	int				line;
	unsigned int	*pixel;
	t_mlx_img		*texture;
	int				meia_tela;
	float			wall_height;
	int				wall_top;
	int				wall_bottom;
	float			y_px;

	meia_tela = 240; //(w_height * (1.0 - 0.2)) / 2
	column = 0;
	while(column < game->projection->width)
	{
		line = 0;
		wall_height = meia_tela / game->player.collisions[column].perpDistance;
		if (game->player.collisions[column].perpDistance == 1)
			 	pixel = NULL;
		wall_top = meia_tela - wall_height;
		wall_bottom = get_wall_bottom(wall_top, game->projection->height, wall_height);
		texture = get_texture(game, game->player.collisions[column].side);
		while(line < meia_tela - wall_height)
		{
			pixel = get_pixel_addres(game->projection, column, line);
			*pixel = game->ceilling;
			line++;
		}
		while(line >= (int)(wall_top) && line <= wall_bottom)
		{
			if (line > 499)
				pixel = NULL;
			pixel = get_pixel_addres(game->projection, column, line);
			y_px = (line - wall_top) / (wall_height * 2);
			//printf("line[%i]\ty_px%f\n",line,y_px);
			if(game->player.collisions[column].side == NORTH || game->player.collisions[column].side == SOUTH)
			{
				*pixel = get_texture_pixel(texture, game->player.collisions[column].point.x - (int)game->player.collisions[column].point.x, y_px);
			}
			else
			{
				*pixel = get_texture_pixel(texture, game->player.collisions[column].point.y - (int)game->player.collisions[column].point.y, y_px);
			}
			color_shade(game->player.collisions[column].perpDistance, pixel);
			line++;
		}
		while(line < game->projection->height){
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
			if (line < height_relation - wall_height)
			 	*pixel = game->ceilling;
			else if (line > height_relation + wall_height)
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