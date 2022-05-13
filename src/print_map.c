/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:46:00 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/12 15:43:24 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	get_pixels_per_square(t_strmap	*map, int max_w, int max_h);

void	print_map(t_cub3d *game)
{
	int	pps; //pixel per square
	int	line;
	int	square;
	int	pos;
	int	data_pos;
	int	offsets[3]; //horizontal / vertical / total em bytes

	pps = get_pixels_per_square(game->map, w_width / 2 , w_height);
	offsets[0] = ((w_width / 2) - pps * game->map->columns) / 2;
	offsets[1] = (w_height - pps * game->map->lines) / 2;
	offsets[2] = get_byte_offset(game->mlx->img, offsets[0], offsets[1]);
	if (pps)
	{
		line = 0;
		while (line < game->map->lines)
		{
			square = 0;
			while (square < game->map->columns)
			{
				pos = line * game->map->columns + square;
				data_pos = square * pps + (pps * game->mlx->img->width * line) + offsets[2]/4;
				if ((char)game->map->map[pos] == ' ')
					print_square(game->mlx->img, &((unsigned int *)game->mlx->img->data)[data_pos], pps, 0x00ffffff);
				else if((char)game->map->map[pos] == '1')
					print_square(game->mlx->img, &((unsigned int *)game->mlx->img->data)[data_pos], pps, 0x009c000d);
				else if((char)game->map->map[pos] == '0')
					print_square(game->mlx->img, &((unsigned int *)game->mlx->img->data)[data_pos], pps, 0x00ff924f);
				else
					print_square(game->mlx->img, &((unsigned int *)game->mlx->img->data)[data_pos], pps, 0x0007e637);
				square++;
			}
			line++;
		}
	}
}

static int	get_pixels_per_square(t_strmap	*map, int max_w, int max_h)
{
	int	max_size[2];

	max_size[0] = max_w / map->columns;
	max_size[1] = max_h / map->lines;
	if (max_size[0] > max_size[1])
		return (max_size[1]);
	return (max_size[0]);
}
