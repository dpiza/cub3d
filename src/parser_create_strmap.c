/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_create_strmap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:55:26 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/27 18:33:27 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	get_map_max_len(char **first_line, int n_lines);
static void	map_to_str(char **dest, char **first_line, \
			int n_lines, int line_size);

t_strmap	*new_strmap(void)
{
	t_strmap	*new_map;

	new_map = ft_calloc(1, sizeof(t_strmap));
	new_map->map = NULL;
	return (new_map);
}

void	load_strmap(t_strmap *strmap, t_map *map)
{
	char	**first_line;
	char	**last_line;

	first_line = get_map_first_line(map);
	last_line = get_map_last_line(first_line);
	strmap->lines = last_line - first_line + 1;
	if (strmap->lines < 0)
		strmap->lines = 0;
	strmap->columns = get_map_max_len(first_line, strmap->lines);
	strmap->map = ft_calloc((strmap->lines * strmap->columns) + 1, 1);
	map_to_str(&strmap->map, first_line, strmap->lines, strmap->columns);
}

void	destroy_strmap(t_strmap *strmap)
{
	if (strmap)
	{
		if (strmap->map)
			free(strmap->map);
		free(strmap);
		strmap = NULL;
	}
}

int	get_map_max_len(char **first_line, int n_lines)
{
	int	local_len;
	int	max_len;
	int	line_n;

	line_n = 0;
	max_len = 0;
	while (line_n < n_lines)
	{
		local_len = ft_strlen((const char *)first_line[line_n]);
		if (first_line[line_n][local_len - 1] == '\n')
			local_len -= 1;
		line_n++;
		if (local_len > max_len)
			max_len = local_len;
	}
	return (max_len);
}

void	map_to_str(char **dest, char **first_line, int n_lines, int line_size)
{
	int	l_i;
	int	char_i;
	int	local_len;

	l_i = 0;
	while (l_i < n_lines)
	{
		local_len = ft_strlen((const char *)first_line[l_i]) - 1;
		char_i = 0;
		while (char_i < local_len)
		{
			(*dest)[(l_i * line_size) + char_i] = first_line[l_i][char_i];
			char_i++;
		}
		while (char_i < line_size)
		{
			(*dest)[(l_i * line_size) + char_i] = ' ';
			char_i++;
		}
		l_i++;
	}
}
