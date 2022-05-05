/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_eval_map_rules.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:41:02 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/05 12:51:42 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int		get_map_max_len(char **first_line, int n_lines)
{
	int	local_len;
	int	max_len;
	int	line_n;

	line_n = 0;
	max_len = 0;
	while (line_n < n_lines)
	{
		local_len = ft_strlen(first_line[line_n]);
		if (first_line[line_n][local_len - 1] == '\n')
			local_len -= 1;
		line_n++;
		if (local_len > max_len)
			max_len = local_len;
	}
	return (max_len);
}


void	print_strmap(char *map,int line_size)
{
	int	l;
	int	map_len;

	l = 0;
	map_len = ft_strlen(map);
	while (l < map_len)
	{
		write(1, map + l, line_size);
		write(1, "\n", 1);
		l += line_size;
	}
}

void	convert_into_string(char **dest, char **first_line, int n_lines, int line_size)
{
	int	line_count;
	int	char_count;
	int	local_len;

	line_count = 0;
	while (line_count < n_lines)
	{
		local_len = ft_strlen(first_line[line_count]) - 1; // there is a -1 because each line has its own \n.
		char_count = 0;
		while (char_count < local_len)
		{
			(*dest)[(line_count * line_size) + char_count] = first_line[line_count][char_count];
			char_count++;
		}
		while (char_count < line_size)
		{
			(*dest)[(line_count * line_size) + char_count] = ' ';
			char_count++;
		}
		line_count++;
	}
}

unsigned char	get_char_at(t_strmap *map, int x, int y)
{
	int	pos;
	if (x >= 0 && x < map->columns && y >= 0 && y < map->lines)
	{
		pos = x + (y * (map->columns));
		return (map->map[pos]);
	}
	return (0);
}

int		is_map_edge(t_strmap *map, int x, int y)
{
	int	mask;

	mask = 0;
	mask = x == 0;
	mask |= x == map->columns - 1;
	mask |= y == 0;
	mask |= y == map->lines - 1;
	return (mask);
}

int		inner_content_touch_invalid_char(t_strmap *map, int x, int y)
{
	unsigned char	boundaries[4];
	int				invalid_b;

	boundaries[0] = get_char_at(map, x, y - 1);
	boundaries[1] = get_char_at(map, x, y + 1);
	boundaries[2] = get_char_at(map, x - 1, y);
	boundaries[3] = get_char_at(map, x + 1, y);
	invalid_b = 0;
	invalid_b |= boundaries[0] == ' ' || boundaries[0] == 0;
	invalid_b |= boundaries[1] == ' ' || boundaries[1] == 0;
	invalid_b |= boundaries[2] == ' ' || boundaries[2] == 0;
	invalid_b |= boundaries[3] == ' ' || boundaries[3] == 0;
	return (invalid_b);
}

int		map_is_walled(t_strmap	*map)
{
	int	l;
	int	c;
	int	is_ok;

	l = 0;
	is_ok = 1;
	while (l < map->lines && is_ok)
	{
		c = 0;
		while (c < map->columns && is_ok)
		{
			if (is_map_edge(map, c, l))
			{
				if (ft_strchr("0NSEW",(int) get_char_at(map, c, l)))
				{
					is_ok = 0;
					break;
				}
			}
			else
			{
				if (ft_strchr("0NSEW",get_char_at(map, c, l)))
				{
					if (inner_content_touch_invalid_char(map, c, l))
					{
						is_ok = 0;
						break;
					}
				}
			}
			c++;
		}
		l++;
	}
	return (is_ok);
}

void	print_map_error(t_map *map)
{
	char *msgs[7];
	int		i;
	int		mask;

	msgs[0] = "Error: Map not found.\n";
	msgs[1] = "Error: Perimeter error.\n";
	msgs[2] = "Error: Map has invalid character.\n";
	msgs[3] = "Error: Unecessary lines with garbage.\n";
	msgs[4] = "Error: Map too short.\n";
	msgs[5] = "Error: Map not properly walled.\n";
	msgs[6] = "Error: Duplicated parameter.\n";
	i = 0;
	while (i < 7)
	{
		mask = 1 << i;
		if (mask & map->status)
			printf("%s", msgs[i]);
		i++;
	}
}

void	eval_map_rules(t_map *map, t_strmap *strmap)
{
	print_strmap(strmap->map, strmap->columns);
	if (!map_is_walled(strmap))
	{
		map->is_ok = 0;
		map->status |= MAP_NOT_WALLED;
	}
}