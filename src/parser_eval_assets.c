/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_eval_assets.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:49:33 by dpiza             #+#    #+#             */
/*   Updated: 2022/05/05 18:04:58 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	fill_texture_path(t_map *map, char *line)
{
	if (line[0] == 'N')
	{
		if(!map->no_path)
			map->no_path = ft_strdup(ft_strchr(line, '.'));
		else
			map->status |= DUPLICATED_PARAMETER;
	}
	else if (line[0] == 'S')
	{
		if(!map->so_path)
			map->so_path = ft_strdup(ft_strchr(line, '.'));
		else
			map->status |= DUPLICATED_PARAMETER;
	}
	else if (line[0] == 'W')
	{
		if(!map->we_path)
			map->we_path = ft_strdup(ft_strchr(line, '.'));
		else
			map->status |= DUPLICATED_PARAMETER;
	}
	else if (line[0] == 'E')
	{
		if(!map->ea_path)
			map->ea_path = ft_strdup(ft_strchr(line, '.'));
		else
			map->status |= DUPLICATED_PARAMETER;
	}
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
			map->ceiling_c[i] = ft_atoi(color[i]);
		i++;
	}
	ft_split_free(&color);
}



void	print_struct(t_map *map)
{
	printf("no_path: %s\nso_path: %s\nwe_path: %s\nea_path: %s\nfloor_c[0]: %d\nfloor_c[1]: %d\nfloor_c[2]: %d\nceiling_c[0]: %d\nceiling_c[1]: %d\nceiling_c[2]: %d\n",
		map->no_path, map->so_path, map->we_path, map->ea_path,
		map->floor_c[0], map->floor_c[1], map->floor_c[2],
		map->ceiling_c[0], map->ceiling_c[1], map->ceiling_c[2]);
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
	//print_struct(map);
}
