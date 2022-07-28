/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_eval_assets.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:49:33 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/27 16:49:41 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	fill_texture_path(t_map *map, char *line)
{
	if (line[0] == 'N' && !map->no_path)
		map->no_path = ft_strdup(get_path(line));
	else if (line[0] == 'S' && !map->so_path)
		map->so_path = ft_strdup(get_path(line));
	else if (line[0] == 'W' && !map->we_path)
		map->we_path = ft_strdup(get_path(line));
	else if (line[0] == 'E' && !map->ea_path)
		map->ea_path = ft_strdup(get_path(line));
	else
		map->status |= DUPLICATED_PARAMETER;
}

static void	fill_color(t_map *map, char *line)
{
	char	**color;
	char	plane;
	int		i;

	plane = line[0];
	line++;
	while (ft_isspace(*line))
		line++;
	color = ft_split(line, ',');
	i = 0;
	while (color[i])
	{
		if (plane == 'F')
			map->floor_c[i] = ft_atoi(color[i]);
		else
			map->ceilling_c[i] = ft_atoi(color[i]);
		i++;
	}
	ft_split_free(&color);
}

void	free_t_map(t_map *map)
{
	free(map->no_path);
	free(map->so_path);
	free(map->we_path);
	free(map->ea_path);
	ft_split_free(&map->lines);
	free(map);
}

void	eval_assets(t_map *map)
{
	char	**map_lines;

	map_lines = map->lines;
	while (*map_lines)
	{
		if (!is_empty_line(*map_lines))
		{
			if (is_valid_texture_line(*map_lines))
				fill_texture_path(map, *map_lines);
			else if (is_valid_color_line(*map_lines))
				fill_color(map, *map_lines);
			else if (!is_valid_map_line(*map_lines))
				map->status |= GARBAGE_LINES;
		}
		map_lines++;
	}
}
