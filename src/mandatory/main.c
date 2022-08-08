/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:48:44 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/29 15:38:33 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int argc, char *argv[])
{
	t_map	*map;
	t_cub3d	*game;

	(void)argc;
	(void)argv;
	if (argc < 2)
	{
		printf("Error\nMissing map path\n");
		return (1);
	}
	if (argc > 2)
	{
		printf("Error\ntoo many arguments\n");
		return (1);
	}
	map = load_map(argv[1]);
	eval_map(map);
	if (map->status == OK)
	{
		game = load_game(map);
		if (game)
			game_run(game);
	}
	free_t_map(map);
	return (0);
}
