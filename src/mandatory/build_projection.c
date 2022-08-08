/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_projection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:11:45 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/28 21:13:59 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

unsigned int	get_texture_pixel(t_mlx_img *img, float column, float line)
{
	unsigned int	*pixel;
	int				texture_x;

	pixel = img->data;
	texture_x = (int)(64 * column);
	pixel += (unsigned int)texture_x + (int)(line * 64)*64;
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

void	write_column(t_mlx_img *projection, t_int_point *xy, \
						int end, unsigned int color)
{
	unsigned int	*pixel;

	while (xy->y < end)
	{
		pixel = get_pixel_address(projection, xy->x, xy->y);
		*pixel = color;
		xy->y++;
	}
}

void	write_texture_collumn(t_cub3d *game, t_int_point *xy, \
						t_wall_data *wall, t_collision *collision)
{
	unsigned int	*pixel;
	t_point			relative_xy;
	int				last_line;
	t_mlx_img		*texture;

	last_line = wall->bottom;
	if (wall->bottom > game->projection->height)
		last_line = game->projection->height;
	texture = get_texture(game, collision->side);
	while (xy->y >= (int)(wall->top) && xy->y <= last_line)
	{
		pixel = get_pixel_address(game->projection, xy->x, xy->y);
		relative_xy.x = (collision->point.x - (int)collision->point.x);
		relative_xy.x += (collision->point.y - (int)collision->point.y);
		relative_xy.y = (xy->y - wall->top) / (wall->height);
		*pixel = get_texture_pixel(texture, relative_xy.x, relative_xy.y);
		xy->y++;
	}
}

void	build_projection(t_cub3d *game)
{
	t_int_point		column_line;
	int				default_height;
	t_wall_data		wall;
	t_collision		collision;

	default_height = 480;
	column_line.x = 0;
	while (column_line.x < game->projection->width)
	{
		column_line.y = 0;
		collision = game->player.collisions[column_line.x];
		wall.height = default_height / collision.perp_distance;
		wall.top = (game->projection->height - wall.height) / 2;
		wall.bottom = wall.top + wall.height;
		write_column(game->projection, &column_line, wall.top, game->ceilling);
		write_texture_collumn(game, &column_line, &wall, &collision);
		write_column(game->projection, &column_line, \
			game->projection->height, game->floor);
		column_line.x++;
	}
}
