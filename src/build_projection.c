/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_projection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:11:45 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/27 15:36:08 by hde-camp         ###   ########.fr       */
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

void	write_column(t_mlx_img *projection, t_int_point *xy, int end, unsigned int color)
{
	unsigned int	*pixel;

	while (xy->y < end)
	{
		pixel = get_pixel_addres(projection, xy->x, xy->y);
		*pixel = color;
		xy->y++;
	}
}
 void	write_texture_collumn(t_cub3d	*game, t_int_point *xy, t_wall_data *wall, t_collision *collision)
 {
	unsigned int	*pixel;
	t_point			relative_xy;
	int				last_line;
	t_mlx_img		*texture;

	last_line = wall->bottom;
	if (wall->bottom > game->projection->height)
		last_line = game->projection->height;
	texture = get_texture(game, collision->side);
	while(xy->y >= (int)(wall->top) && xy->y <= last_line)
	{
		pixel = get_pixel_addres(game->projection, xy->x, xy->y);
		relative_xy.x = (collision->point.x - (int)collision->point.x) + (collision->point.y - (int)collision->point.y);
		relative_xy.y = (xy->y - wall->top) / (wall->height);
		*pixel = get_texture_pixel(texture, relative_xy.x, relative_xy.y);

		xy->y++;
	}
}
void	build_projection_two(t_cub3d *game)
{
	t_int_point		column_line;
	int				default_height;
	t_wall_data		wall;
	t_collision		collision;

	default_height = 480;
	column_line.x = 0;
	while(column_line.x < game->projection->width)
	{
		column_line.y = 0;
		collision = game->player.collisions[column_line.x];
		wall.height = default_height / collision.perpDistance;
		wall.top = (game->projection->height - wall.height) / 2;
		wall.bottom = wall.top + wall.height;
		write_column(game->projection, &column_line, wall.top, game->ceilling);
		write_texture_collumn(game, &column_line, &wall, &collision);
		write_column(game->projection, &column_line, game->projection->height, game->floor);
		column_line.x++;
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
		texture = get_texture(game, game->player.collisions[column].side);
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
					*pixel = get_texture_pixel(texture, game->player.collisions[column].point.x - (int)game->player.collisions[column].point.x, y_px);
				}
				else
				{
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