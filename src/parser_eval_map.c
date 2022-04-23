/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_eval_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 23:04:16 by hde-camp          #+#    #+#             */
/*   Updated: 2022/04/22 23:46:10 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static	int	is_map_allowed_character(char c)
{
	char	allowed[8];
	int		i;

	*allowed = "10NSEW";
	i = 0;
	while (i < 8)
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

void	eval_map(t_map	*map)
{
	
}
