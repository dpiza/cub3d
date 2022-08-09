/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_line_checkers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:06:16 by hde-camp          #+#    #+#             */
/*   Updated: 2022/08/09 13:12:49 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	is_xpm(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 5)
		return (0);
	if (!ft_strncmp(path + len - 5, ".xpm", 4))
		return (1);
	return (0);
}

char	*get_path(char *line)
{
	char	*path;

	path = line + 2;
	while (ft_isspace(*path))
		path++;
	if (*path != '.' && *path != '/')
		return (NULL);
	return (path);
}

int	is_valid_map_line(char *line)
{
	int	len;
	int	i;

	len = ft_strlen((const char *)line);
	i = 0;
	while (i < len - 1)
	{
		if (!is_map_allowed_character(line[i]))
			return (0);
		i++;
	}
	if (!ft_strchr(MAP_LINE, (int) line[i]))
	{
		return (0);
	}
	return (1);
}

int	is_empty_line(char *line)
{
	while (*line)
	{
		if (!ft_isspace((char) *line))
			return (0);
		line++;
	}
	return (1);
}
