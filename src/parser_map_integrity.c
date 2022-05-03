/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_integrity.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:58:11 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/02 22:44:26 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static	void	eval_trailing_garbage(t_map *map, char **map_last_line);

void	map_integrity(t_map *map)
{
	char	**map_first_line;
	char	**map_last_line;

	map_first_line = get_map_first_line(map);
	map_last_line = get_map_last_line(map_first_line);
	if (map_first_line && map_last_line)
	{
		if (map_last_line - map_first_line)
		{
			eval_trailing_garbage(map, map_last_line);
		}
		else
		{
			map->status |= MAP_TOO_SHORT;
		}
	}
	else
		map->status |= NO_MAP;
}

static	void	eval_trailing_garbage(t_map *map, char **map_last_line)
{
	int		i;
	int		keep_going;
	char	*line;

	i = 0;
	keep_going = 1;
	map_last_line++;
	while (map_last_line[i] && keep_going)
	{
		line = map_last_line[i];
		while (*line)
		{
			if (!ft_isspace(*line))
			{
				map->is_ok = 0;
				map->status |= GARBAGE_LINES;
				keep_going = 0;
				break;
			}
			line++;
		}
		i++;
	}
}
