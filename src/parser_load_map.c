/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_load_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:14:11 by hde-camp          #+#    #+#             */
/*   Updated: 2022/04/22 17:28:20 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_map	*load_map(const char *path)
{
	t_map	*map;
	int		fd;


	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Arquivo %s nao encontrado.\n");
		exit(EXIT_FAILURE);
	}
	map = malloc(sizeof(map));
	return (map);
}