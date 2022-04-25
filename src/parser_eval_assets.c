/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_eval_assets.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:49:33 by dpiza             #+#    #+#             */
/*   Updated: 2022/04/25 18:14:20 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	fill_texture_path(t_map *map, char *line)
{
	if (line[0] == 'N')
		map->no_path = ft_strdup(ft_strchr(line, '.'));
	else if (line[0] == 'S')
		map->so_path = ft_strdup(ft_strchr(line, '.'));
	else if (line[0] == 'W')
		map->we_path = ft_strdup(ft_strchr(line, '.'));
	else if (line[0] == 'E')
		map->ea_path = ft_strdup(ft_strchr(line, '.'));
}

static int	is_valid_texture(char *line)
{
	int			i;
	static char	*path[4] = {
		"NO",
		"SO",
		"WE",
		"EA"
	};

	if (!line)
		return (0);
	i = 0;
	while (path[i] && ft_strncmp(line, path[i], 2) != 0)
		i++;
	if (i > 3)
		return (0);
	line += 2;
	while (ft_isspace(*line))
		line++;
	if (*line != '.')
		return (0);
	line[ft_strlen(line) - 1] = '\0';
	if (open(ft_strchr(line, '.'), O_RDONLY) > 0)
		return (1);
	else
		perror("Load Asset");
}

static void	fill_color(t_map *map, char *line)
{
	char	**color;
	int		i;

	i = 0;
	if (line[0] == 'F')
	{
		color = ft_split(line + 2, ',');
		while (color[i])
		{
			printf("Atoi Color[i]: %i\n", ft_atoi(color[i]));
			map->floor_c[i] = ft_atoi(color[i]);
			i++;
		}
	}
	else if (line[0] == 'C')
	{
		color = ft_split(line + 2, ',');
		while (color[i])
		{
			printf("Atoi Color[i]: %i\n", ft_atoi(color[i]));
			map->ceiling_c[i] = ft_atoi(color[i]);
			i++;
		}
	}
	ft_split_free(&color);
}

static int	is_valid_color(char *line)
{
	char	**color;
	int		i;

	if (ft_strncmp(line, "F", 1) == 0
		|| ft_strncmp(line, "C", 1) == 0)
	{
		i = 0;
		line[ft_strlen(line) - 1] = '\0';
		color = ft_split(line + 2, ',');
		while (color[i] && ft_atoi(color[i]) >= 0 && ft_atoi(color[i]) < 256)
		{
			printf("Color[i]: %s\n", color[i]);
			i++;
		}
		ft_split_free(&color);
		if (i > 2)
			return (1);
	}
	return (0);
}

void	print_struct(t_map *map)
{
	printf("no_path: %s\nso_path: %s\nwe_path: %s\nea_path: %s\nfloor_c[0]: %d\nfloor_c[1]: %d\nfloor_c[2]: %d\nceiling_c[0]: %d\nceiling_c[1]: %d\nceiling_c[2]: %d\n",
	map->no_path, map->so_path, map->we_path, map->ea_path,
	map->floor_c[0], map->floor_c[1], map->floor_c[2],
	map->ceiling_c[0], map->ceiling_c[1], map->ceiling_c[2]);
}

void	free_struct(t_map *map)
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
		if (is_valid_texture(*map_lines))
			fill_texture_path(map, *map_lines);
		if (is_valid_color(*map_lines))
			fill_color(map, *map_lines);
		map_lines++;
	}
	print_struct(map);
	free_struct(map);
}
