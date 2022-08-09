/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_load_map_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:14:11 by hde-camp          #+#    #+#             */
/*   Updated: 2022/08/09 12:42:16 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	unload_map(t_map *map)
{
	int	i;

	if (map)
	{
		if (map->lines)
		{
			i = 0;
			while (map->lines[i])
				free(map->lines[i++]);
			free(map->lines);
		}
		free(map);
	}
}

void	replace_references(char ***old, char ***new, char *new_line)
{
	int	i;

	i = 0;
	while ((*old)[i])
	{
		(*new)[i] = (*old)[i];
		i++;
	}
	(*new)[i] = new_line;
}

void	add_next_lines(char *new_line, char ***lines)
{
	int		cur_size;
	char	**new_line_array;

	if (!lines[0])
	{
		*lines = ft_calloc(2, sizeof(char *));
		*lines[0] = new_line;
	}
	else
	{
		cur_size = 0;
		while ((*lines)[cur_size])
			cur_size++;
		new_line_array = ft_calloc(cur_size + 2, sizeof(char *));
		replace_references(lines, &new_line_array, new_line);
		free((*lines));
		(*lines) = new_line_array;
	}
}

t_map	*load_map(const char *path)
{
	t_map	*map;
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nFile %s not found.\n", path);
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	if (!line)
	{
		printf("Error\nFile %s not found.\n", path);
		exit(EXIT_FAILURE);
	}
	map = ft_calloc(1, sizeof(t_map));
	while (line)
	{
		add_next_lines(line, &map->lines);
		line = get_next_line(fd);
	}
	return (map);
}
