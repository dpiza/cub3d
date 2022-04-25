/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_integrity.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:58:11 by hde-camp          #+#    #+#             */
/*   Updated: 2022/04/25 15:54:41 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static	int	is_map_allowed_character(char c);
static	int	is_map_first_char(char c);
static	int	is_map_line(char *line);
static	int	is_map_first_line(char *line);
static	char **get_first_map_line(t_map	*map);
static	char **get_last_map_line(char **first_line);

void	map_integrity(t_map *map)
{
	char	**first_map_line;
	char	**last_map_line;

	first_map_line = get_first_map_line(map);
	if (first_map_line)
	{
		printf("found first line\n");
		last_map_line = get_last_map_line(first_map_line);
		(void)last_map_line;
	}
}

static	int	is_map_allowed_character(char c)
{
	char	*allowed;
	int		i;

	allowed = "10NSEW";
	i = 0;
	while (i < 8)
	{
		if (allowed[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	int	is_map_first_char(char c)
{
	char	*allowed;
	int		i;

	allowed = " 10";
	i = 0;
	while (i < 3)
	{
		if (allowed[i] == c)
			return (1);
		i++;
	}
	return (0);
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

static	char **get_first_map_line(t_map	*map)
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

static	char **get_last_map_line(char **first_line)
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
