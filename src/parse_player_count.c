/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:41:26 by hde-camp          #+#    #+#             */
/*   Updated: 2022/08/02 19:36:43 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	eval_player_count(t_map	*map, t_strmap *strmap)
{
	int	x;
	int	y;
	int	players;

	y = 0;
	players = 0;
	while (y < strmap->lines)
	{
		x = 0;
		while (x < strmap->columns)
		{
			if (ft_strchr("NSEW", (int)get_char_at(strmap, x, y)))
				players++;
			x++;
		}
		y++;
	}
	if (players != 1)
		map->status |= PLAYER_COUNT;
}
