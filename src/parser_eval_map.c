/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_eval_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 23:04:16 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/28 10:06:57 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	print_map_error(t_map *map);

void	eval_map(t_map	*map)
{
	t_strmap	*strmap;

	strmap = new_strmap();
	load_strmap(strmap, map);
	map_integrity(map);
	eval_map_rules(map, strmap);
	destroy_strmap(strmap);
	eval_assets(map);
	print_map_error(map);
}

void	print_map_error(t_map *map)
{
	char	*msgs[7];
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
	mask = 1;
	while (i < 7)
	{
		mask = mask << 1;
		if (mask & map->status)
			printf("%s", msgs[i]);
		i++;
	}
}
