/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:15:20 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/23 16:15:33 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	square_check(t_cub3d *game, float x, float y)
{
	int		pos_array;
	char	map_obj;
	
	pos_array = (int)game->map->columns * (int)y + (int)x;
	map_obj = game->map->map[pos_array];
	// printf("Map obj %c\n", map_obj); // printa o objeto do mapa no terminal
	return (map_obj);
}