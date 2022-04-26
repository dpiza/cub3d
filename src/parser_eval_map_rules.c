/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_eval_map_rules.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:41:02 by hde-camp          #+#    #+#             */
/*   Updated: 2022/04/26 16:32:54 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int		get_map_max_len(char **first_line, int line_count)
{
	int	local_len;
	int	max_len;
	int	line_n;

	line_n = 0;
	max_len = 0;
	while (line_n < line_count)
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

void	eval_map_rules(t_map *map, char **first_line, char **last_line)
{
	char	*map_as_str;
	int		line_n;

	line_n = first_line - last_line + 1;
	map_as_str = ft_calloc((get_map_max_len(first_line, line_n) * line_n), 1); //this is not null terminated!
	//get maximum length and padronize map into a long string.
	//only "10 NSEW"
	//map must be closed by walls
	//only one player
}