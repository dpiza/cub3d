/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_eval_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 19:12:22 by hde-camp          #+#    #+#             */
/*   Updated: 2022/08/03 19:13:11 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	is_valid_texture_line(char *line, t_map	*map)
{
	char		*path;
	int			i;
	static char	*side[5] = {"NO", "SO", "WE", "EA", 0};
	int			fd;

	i = 0;
	while (side[i] && ft_strncmp(line, side[i], 2) != 0)
		i++;
	if (i > 3)
		return (0);
	path = get_path(line);
	if (!path)
		return (0);
	if (!is_xpm(path))
		return (0);
	path[ft_strlen((const char *)path) - 1] = '\0';
	fd = open(path, O_RDONLY);
	if (fd > 0)
	{
		close(fd);
		return (1);
	}
	map->status |= GARBAGE_LINES;
	return (0);
}

int	is_valid_color_line(char *line)
{
	char	**color;
	int		i;

	if (ft_strncmp(line, "F", 1) && ft_strncmp(line, "C", 1))
		return (0);
	line++;
	while (ft_isspace(*line))
		line++;
	if (!ft_isdigit(*line))
		return (0);
	line[ft_strlen((const char *)line) - 1] = '\0';
	color = ft_split(line, ',');
	i = 0;
	while (color[i] && ft_atoi(color[i]) >= 0 && ft_atoi(color[i]) < 256)
		i++;
	ft_split_free(&color);
	if (i > 2)
		return (1);
	return (0);
}
