/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:46:00 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/11 16:26:02 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	print_square(t_mlx_img	*img, unsigned int *dest_origin, int sqr_size, unsigned int color);
static int	get_pixels_per_square(t_strmap	*map, int max_w, int max_h);

void	print_map(t_cub3d *game)
{
	int	pps; //pixel per square
	int	line;
	int	square;
	int	pos;
	int	data_pos;

	pps = get_pixels_per_square(game->map, w_width / 2 , w_height / 2);
	if (pps)
	{
		line = 0;
		while (line < game->map->lines)
		{
			square = 0;
			while (square < game->map->columns)
			{
				pos = line * game->map->columns + square;
				data_pos = square * pps + (pps * game->mlx->img->width * line);
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

static void	print_square(t_mlx_img	*img, unsigned int *dest_origin, int sqr_size, unsigned int color)
{
	unsigned int	*dest;
	int	i[2];

	dest = dest_origin;
	i[0] = 0;
	while (i[0] < sqr_size)
	{
		i[1] = 0;
		while (i[1] < sqr_size)
		{
			*dest = color;
			dest++;
			i[1]++;
		}
		dest += img->width - sqr_size;
		i[0]++;
	}
}


static int	get_pixels_per_square(t_strmap	*map, int max_w, int max_h)
{
	int	n;
	int	l;

	n = map->columns;
	if (map->lines > n)
		n = map->lines;
	l = max_w;
	if (max_h > l)
		l = max_h;
	return (l / n);
}
