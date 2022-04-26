/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_integrity.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:58:11 by hde-camp          #+#    #+#             */
/*   Updated: 2022/04/25 17:41:36 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static	int	is_map_line(char *line);
static	int	is_map_first_line(char *line);
static	char	**get_map_first_line(t_map	*map);
static	char	**get_map_last_line(char **first_line);
static	void	eval_trailing_garbage(t_map *map, char **map_last_line);

void	map_integrity(t_map *map)
{
	char	**map_first_line;
	char	**map_last_line;

	map_first_line = get_map_first_line(map);
	if (map_first_line)
	{
		map_last_line = get_map_last_line(map_first_line);
		if (map_first_line - map_last_line)
		{
			eval_trailing_garbage(map, map_last_line);
		}
		else
		{
			map->status = MAP_TOO_SHORT;
		}
	}
	else
		map->status = NO_MAP;
}

static	void	eval_trailing_garbage(t_map *map, char **map_last_line)
{
	int		i;
	char	*line;

	i = 0;
	while (map_last_line[i] && map->status == OK)
	{
		line = map_last_line[i];
		while (line)
		{
			if (!ft_isspace(*line))
			{
				map->status = GARBAGE_LINES;
				break;
			}
			line++;
		}
	}
}

static	int	is_map_line(char *line)
{
	if (line)
	{
		while (ft_isspace(*line))
			line++;
		if (line)
		{
			if (is_map_allowed_character(*line))
				return (1);
			else
				return (0);
		}
		return (0);
	}
	return (0);
}

static	int	is_map_first_line(char *line)
{
	if (line)
	{
		while (ft_isspace(*line))
			line++;
		if (line)
		{
			if (is_map_first_char(*line))
				return (1);
			else
				return (0);
		}
		return (0);
	}
	return (0);
}

static	char **get_map_first_line(t_map	*map)
{
	char **map_lines;

	map_lines = map->lines;
	while (*map_lines)
	{
		if (is_map_first_line(*map_lines))
			return (map_lines);
		map_lines++;
	}
	return (NULL);
}

static	char **get_map_last_line(char **first_line)
{
	char	**last_line;

	last_line = first_line;
	while (is_map_line(*last_line))
	{
		last_line++;
	}
	last_line--;
	return (last_line);
}
