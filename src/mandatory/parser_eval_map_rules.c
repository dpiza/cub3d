/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_eval_map_rules.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:41:02 by hde-camp          #+#    #+#             */
/*   Updated: 2022/08/03 19:11:22 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	is_map_edge(t_strmap *map, int x, int y)
{
	int	mask;

	mask = 0;
	mask = x == 0;
	mask |= x == map->columns - 1;
	mask |= y == 0;
	mask |= y == map->lines - 1;
	return (mask);
}

int	inner_content_touch_invalid_char(t_strmap *map, int x, int y)
{
	unsigned char	boundaries[4];
	int				invalid_b;

	boundaries[0] = get_char_at(map, x, y - 1);
	boundaries[1] = get_char_at(map, x, y + 1);
	boundaries[2] = get_char_at(map, x - 1, y);
	boundaries[3] = get_char_at(map, x + 1, y);
	invalid_b = 0;
	if (boundaries[0])
		invalid_b |= ft_strchr("10NSEW", (int)boundaries[0]) == NULL;
	if (boundaries[1])
		invalid_b |= ft_strchr("10NSEW", (int)boundaries[1]) == NULL;
	if (boundaries[2])
		invalid_b |= ft_strchr("10NSEW", (int)boundaries[2]) == NULL;
	if (boundaries[3])
		invalid_b |= ft_strchr("10NSEW", (int)boundaries[3]) == NULL;
	return (invalid_b);
}

int	eval_walls(t_strmap	*strmap, t_map	*map)
{
	int	l;
	int	c;

	l = 0;
	while (l < strmap->lines)
	{
		c = 0;
		while (c < strmap->columns)
		{
			if (ft_strchr("0NSEW", (int) get_char_at(strmap, c, l)))
			{
				if (is_map_edge(strmap, c, l))
				{
					map->status |= MAP_NOT_WALLED;
					return (0);
				}
			}
			c++;
		}
		l++;
	}
	return (1);
}

int	eval_invalid_chars(t_strmap	*strmap, t_map	*map)
{
	int	l;
	int	c;

	l = 0;
	while (l < strmap->lines)
	{
		c = 0;
		while (c < strmap->columns)
		{
			if (ft_strchr("0NSEW", (int) get_char_at(strmap, c, l)))
			{
				if (inner_content_touch_invalid_char(strmap, c, l))
				{
					map->status |= INVALID_CHARACTER;
					return (0);
				}
			}
			c++;
		}
		l++;
	}
	return (1);
}

void	eval_map_rules(t_map *map, t_strmap *strmap)
{
	if (strmap->map)
	{
		eval_walls(strmap, map);
		eval_invalid_chars(strmap, map);
		eval_player_count(map, strmap);
	}
}
