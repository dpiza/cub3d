/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:55:47 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/07 20:40:14 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	open_door(t_cub3d *game)
{
	t_point	use_pos;

	use_pos.x = game->player.pos.x + game->player.dir.x;
	use_pos.y = game->player.pos.y + game->player.dir.y;
	game->map->map[(int)use_pos.y * game->map->columns + (int)use_pos.x] = 'O';
	set_collisions(game);
}

void	close_door(t_cub3d *game)
{
	t_point	use_pos;

	use_pos.x = game->player.pos.x + game->player.dir.x;
	use_pos.y = game->player.pos.y + game->player.dir.y;
	game->map->map[(int)use_pos.y * game->map->columns + (int)use_pos.x] = 'D';
	set_collisions(game);
}

void	talk(t_cub3d *game)
{
	if (!game->player.in_conversation)
		game->player.in_conversation = 1;
	else
		game->player.in_conversation = 0;
	if (game->player.quest.quest_step <= FOUND_DOOR)
		game->player.quest.quest_step = CODESWORTH;
	game->player.right_click = 0;
}

void	get_key(t_cub3d *game)
{
	char	k;

	k = game->player.aimed_obj;
	if (k == 'J' && game->player.quest.key_one == 0)
	{
		game->player.quest.key_one = 1;
		game->player.notify = 1;
	}
	else if (k == 'K' && game->player.quest.key_two == 0)
	{
		game->player.quest.key_two = 1;
		game->player.notify = 1;
	}
	else if (k == 'L' && game->player.quest.key_three == 0)
	{
		game->player.quest.key_three = 1;
		game->player.notify = 1;
	}
	if (game->player.quest.key_one == 1 \
		&& game->player.quest.key_two == 1 \
		&& game->player.quest.key_three == 1)
		game->player.quest.quest_step = FOUND_KEYS;
}

void	use(t_cub3d *game)
{
	char	map_obj;

	map_obj = game->player.aimed_obj;
	if (map_obj == 'D' && game->player.quest.quest_step != DEFAULT)
		open_door(game);
	if (map_obj == 'O')
		close_door(game);
	if (map_obj == 'C')
		talk(game);
	if (is_in_list(map_obj, PCS))
		get_key(game);
}
