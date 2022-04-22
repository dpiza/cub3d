/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:48:44 by hde-camp          #+#    #+#             */
/*   Updated: 2022/04/22 17:24:58 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int argc, char *argv[])
{
	char *line;
	int	map_fd;

	(void)argc;
	(void)argv;
	map_fd = open("./maps/test.cub", O_RDONLY);
	if (map_fd != -1)
	{
		line = get_next_line(map_fd);
		while(line)
		{
			printf("%s",line);
			free(line);
			line = get_next_line(map_fd);
		}
	}
	return (0);
}
