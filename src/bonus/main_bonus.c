/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:48:44 by hde-camp          #+#    #+#             */
/*   Updated: 2022/08/10 21:00:36 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	exit_error(const char *message)
{
	printf("%s", message);
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
		exit_error("Error\nToo many arguments.\n");
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
