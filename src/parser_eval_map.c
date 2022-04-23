/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_eval_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 23:04:16 by hde-camp          #+#    #+#             */
/*   Updated: 2022/04/23 00:31:06 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

//static	int	is_map_allowed_character(char c)
//{
//	char	*allowed;
//	int		i;
//
//	allowed = "10NSEW";
//	i = 0;
//	while (i < 8)
//	{
//		if (allowed[i] == c)
//			return (1);
//		i++;
//	}
//	return (0);
//}

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
		if (is_map_line(*map_lines))
			return (map_lines);
		map_lines++;
	}
	return (NULL);
}

void	eval_map(t_map	*map)
{
	char	**first_map_line;

	first_map_line = get_first_map_line(map);
	if (first_map_line)
	{
		printf("found first line\n");
	}
}
