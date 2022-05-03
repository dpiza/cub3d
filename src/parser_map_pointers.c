/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_pointers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:31:09 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/02 22:41:23 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static	int	is_map_line(char *line);
static	int	is_map_first_line(char *line);

char **get_map_first_line(t_map	*map)
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

char **get_map_last_line(char **first_line)
{
	char	**last_line;

	last_line = first_line;
	while (is_map_line(*last_line))
	{
		last_line++;
	}
	if (last_line)
		last_line--;
	return (last_line);
}

static	int	is_map_line(char *line)
{
	if (line)
	{
		while (ft_isspace(*line))
			line++;
		if (*line)
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
