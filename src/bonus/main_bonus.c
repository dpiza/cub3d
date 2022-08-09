/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:48:44 by hde-camp          #+#    #+#             */
/*   Updated: 2022/08/09 17:21:04 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	exit_error(const char *message)
{
	printf(message);
	exit (1);
}

int	main(int argc, char *argv[])
{
	t_map	*map;
	t_cub3d	*game;

	(void)argc;
	(void)argv;
	if (argc < 2)
		exit_error("Error\nMissing map path.\n");
	if (argc > 2)
		exit_error("Error\ntoo many arguments.\n");
	map = load_map(argv[1]);
	eval_map(map);
	if (map->status == OK)
	{
		game = load_game(map);
		if (game)
			game_run(game);
	}
	else
	{
		free_t_map(map);
		return (1);
	}
	return (0);
}
