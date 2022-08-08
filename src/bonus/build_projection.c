/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_projection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:11:45 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/07 20:37:36 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

unsigned int	get_texture_pixel(t_mlx_img *img, float column, float line)
{
	unsigned int	*pixel;
	int				texture_x;

	pixel = img->data;
	texture_x = (int)(img->width * column);
	pixel += (unsigned int)(texture_x + \
		((int)(line * img->height)) * img->width);
	return (*pixel);
}

t_mlx_img	*get_texture(t_cub3d *game, t_collision *collision)
{
	if (is_in_list(collision->map_obj, TEXTURE_DOOR))
		return (game->texture.door);
	else if (is_in_list(collision->map_obj, PCS))
		return (game->texture.pc);
	else if (collision->map_obj == '2')
		return (game->texture.exit);
	else if (collision->side == NORTH)
		return (game->texture.no);
	else if (collision->side == SOUTH)
		return (game->texture.so);
	else if (collision->side == EAST)
		return (game->texture.ea);
	else
		return (game->texture.we);
}

void	write_column(t_mlx_img *projection, t_int_point *xy, \
						int end, unsigned int color)
{
	unsigned int	*pixel;

	while (xy->y < end)
	{
		pixel = get_pixel_address(projection, xy->x, xy->y);
		*pixel = color;
		color_shade_ceiling(xy, pixel);
		xy->y++;
	}
}

void	write_texture_collumn(t_cub3d *game, t_int_point *xy, \
						t_wall_data *wall, t_collision *collision)
{
	unsigned int	*pixel;
	t_point			relative;
	int				last_line;
	t_mlx_img		*texture;

	last_line = wall->bottom;
	if (wall->bottom > game->projection->height)
		last_line = game->projection->height;
	texture = get_texture(game, collision);
	while (xy->y >= (int)(wall->top) && xy->y <= last_line)
	{
		pixel = get_pixel_address(game->projection, xy->x, xy->y);
		relative.x = (collision->point.x - (int)collision->point.x);
		relative.x += (collision->point.y - (int)collision->point.y);
		relative.y = (xy->y - wall->top) / (wall->height);
		*pixel = get_texture_pixel(texture, relative.x, relative.y);
		color_shade(collision->distance, pixel);
		xy->y++;
	}
}

void	build_projection(t_cub3d *game)
{
	t_int_point		column_line;
	t_wall_data		wall;
	t_collision		collision;

	column_line.x = 0;
	while (column_line.x < game->projection->width)
	{
		column_line.y = 0;
		collision = game->player.collisions[column_line.x];
		wall.height = DEFAULT_HEIGHT / collision.perp_distance;
		wall.top = (game->projection->height - wall.height) / 2;
		wall.bottom = wall.top + wall.height;
		write_column(game->projection, &column_line, wall.top, game->ceilling);
		write_texture_collumn(game, &column_line, &wall, &collision);
		write_column(game->projection, &column_line, \
			game->projection->height, game->floor);
		column_line.x++;
	}
}
