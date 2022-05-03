/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_eval_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 23:04:16 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/03 13:31:29 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	eval_map(t_map	*map)
{
	t_strmap	*strmap;

	strmap = new_strmap();
	load_strmap(strmap, map);
	map_integrity(map);
	eval_map_rules(map, strmap);
	print_map_error(map);
	destroy_strmap(strmap);
}
