/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action_weapon.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:23:33 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/07 20:40:11 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	reload(t_cub3d *game)
{
	if (game->player.firing == 0 && game->player.ammo == 0)
	{
		game->player.ammo = 15;
		game->player.firing = -12;
	}
}

void	shot(t_cub3d *game, t_collision target)
{
	t_sprite_list	*current;

	current = game->sprite_list;
	if (!current)
		return ;
	while (current)
	{
		if ((int)current->sprite->pos.x == (int)target.point.x
			&& (int)current->sprite->pos.y == (int)target.point.y)
		{
			if (clock() % 2 == 1)
				current->sprite->alive = 0;
			else
				current->sprite->shot = 1;
			current->sprite->aggro = 1;
		}
		current = current->next;
	}
}

void	fire(t_cub3d *game)
{
	t_collision	collision;

	if (game->player.firing == 0 && game->player.ammo > 0)
	{
		game->player.firing = 1;
		game->player.ammo--;
		collision = get_sprite_collision(game);
		if (collision.map_obj == 'X')
			shot(game, collision);
	}
}
