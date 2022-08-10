/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:07:41 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/30 16:15:04 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	unlock_door(t_cub3d *game)
{
	t_point	use_pos;

	use_pos.x = game->player.pos.x + game->player.dir.x;
	use_pos.y = game->player.pos.y + game->player.dir.y;
	game->map->map[(int)use_pos.y * game->map->columns + (int)use_pos.x] = 'D';
	set_collisions(game);
	game->player.notify = 71;
}

void	open_use(t_cub3d *game, int *open)
{
	int			y;
	int			x;

	y = W_HEIGHT - game->texture.action_open->height;
	x = W_WIDTH - game->texture.action_open->width;
	if (*open <= ANIMATION_CICLE)
		override_images(game->mlx->img, game->texture.action_closed, x, y);
	else if (*open <= 2 * ANIMATION_CICLE)
		override_images(game->mlx->img, game->texture.action_half, x, y);
	else
		override_images(game->mlx->img, game->texture.action_open, x, y);
	if (*open <= 2 * ANIMATION_CICLE)
		*open += 1;
}

void	close_use(t_cub3d *game, int *open)
{
	int			y;
	int			x;

	y = W_HEIGHT - game->texture.action_open->height;
	x = W_WIDTH - game->texture.action_open->width;
	if (*open > ANIMATION_CICLE)
		override_images(game->mlx->img, game->texture.action_half, x, y);
	else
		override_images(game->mlx->img, game->texture.action_closed, x, y);
	*open -= 1;
}

void	denied(t_cub3d *game)
{
	int			y;
	int			x;

	y = W_HEIGHT - game->texture.action_open->height;
	x = W_WIDTH - game->texture.action_open->width;
	override_images(game->mlx->img, game->texture.action_denied, x, y);
	if (game->player.aimed_obj == 'B'
		&& game->player.quest.quest_step <= CODESWORTH)
		game->player.quest.quest_step = FOUND_DOOR;
}

void	print_action_bar(t_cub3d *game)
{
	static int	open;

	if (is_in_list(game->player.aimed_obj, INTER_OBJ)
		&& game->player.quest.quest_step != DEFAULT)
		open_use(game, &open);
	else if (game->player.aimed_obj == 'C')
		open_use(game, &open);
	else if (open > 0)
		close_use(game, &open);
	else if (game->player.aimed_obj == 'D'
		&& game->player.quest.quest_step == DEFAULT)
		denied(game);
	else if (game->player.aimed_obj == 'B'
		&& game->player.quest.quest_step != FOUND_KEYS)
		denied(game);
	else if (game->player.aimed_obj == 'B'
		&& game->player.quest.quest_step == FOUND_KEYS)
		unlock_door(game);
	else if (game->player.aimed_obj == '2')
	{
		game->player.in_conversation = 1;
		game->player.quest.quest_step = FINISH;
	}
}
