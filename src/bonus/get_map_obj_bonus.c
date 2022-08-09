/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:15:20 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/07 20:38:17 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

char	get_map_obj(t_cub3d *game, float x, float y)
{
	int		pos_array;
	char	map_obj;

	pos_array = (int)game->map->columns * (int)y + (int)x;
	map_obj = game->map->map[pos_array];
	return (map_obj);
}

t_point	get_obj_pos(t_cub3d *game, int index)
{
	t_point	pos;

	pos.y = (float)(index / game->map->columns) + 0.5;
	pos.x = (float)(index % game->map->columns) + 0.5;
	return (pos);
}
