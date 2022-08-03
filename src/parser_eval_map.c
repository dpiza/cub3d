/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_eval_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 23:04:16 by hde-camp          #+#    #+#             */
/*   Updated: 2022/08/02 20:49:02 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	print_map_error(t_map *map);

void	eval_map(t_map	*map)
{
	t_strmap	*strmap;

	strmap = new_strmap();
	map_integrity(map);
	load_strmap(strmap, map);
	eval_map_rules(map, strmap);
	destroy_strmap(strmap);
	eval_configs(map);
	if (map->status)
		print_map_error(map);
}

void	print_map_error(t_map *map)
{
	char	*msgs[8];
	int		i;
	int		mask;

	msgs[0] = "Map not found.\n";
	msgs[1] = "Missing Configuration.\n";
	msgs[2] = "Map has invalid character.\n";
	msgs[3] = "Unecessary or Invalid lines.\n";
	msgs[4] = "Map too short.\n";
	msgs[5] = "Map not properly walled.\n";
	msgs[6] = "Duplicated parameter.\n";
	msgs[7] = "Invalid Player Quantity.\n";
	i = 1;
	mask = 1;
	printf("Error\n");
	if (mask & map->status)
		printf("%s", msgs[0]);
	while (i < 8)
	{
		mask = mask << 1;
		if (mask & map->status)
			printf("%s", msgs[i]);
		i++;
	}
}
