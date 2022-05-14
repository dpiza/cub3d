/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:46:00 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/13 18:14:20 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	print_map(t_cub3d *game)
{
	int	line;
	int	square;
	int	pos;
	int	data_pos;
	int	offset; //horizontal / vertical / total em bytes

	offset = get_byte_offset(game->mlx->img, game->map->pos.x, game->map->pos.y) / 4;
	if (game->map->minimap_pps)
	{
		line = 0;
		while (line < game->map->lines)
		{
			square = 0;
			while (square < game->map->columns)
			{
				pos = line * game->map->columns + square;
				data_pos = square * game->map->minimap_pps + (game->map->minimap_pps * game->mlx->img->width * line) + offset;
				if ((char)game->map->map[pos] == ' ')
					print_square(game->mlx->img, &((unsigned int *)game->mlx->img->data)[data_pos], game->map->minimap_pps, 0x00ffffff);
				else if((char)game->map->map[pos] == '1')
					print_square(game->mlx->img, &((unsigned int *)game->mlx->img->data)[data_pos], game->map->minimap_pps, 0x009c000d);
				else if((char)game->map->map[pos] == '0')
					print_square(game->mlx->img, &((unsigned int *)game->mlx->img->data)[data_pos], game->map->minimap_pps, 0x00ff924f);
				else
					print_square(game->mlx->img, &((unsigned int *)game->mlx->img->data)[data_pos], game->map->minimap_pps, 0x009c000d);
				square++;
			}
			line++;
		}
	}
}
