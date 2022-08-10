/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_sprites_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 21:32:25 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/10 17:32:44 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	update_sprites_distance(t_cub3d *game)
{
	t_sprite_list	*current;
	t_point			subtract_pos;

	current = game->sprite_list;
	if (!current)
		return ;
	while (current)
	{
		subtract_pos = subtract_vector(&game->player.pos, \
			&current->sprite->pos);
		current->sprite->distance = sqrt(subtract_pos.x * subtract_pos.x + \
			subtract_pos.y * subtract_pos.y);
		current = current->next;
	}
}

void	get_map_sprites(t_cub3d *game)
{
	int	i;

	i = 0;
	while (i < game->map->columns * game->map->lines)
	{
		if (is_in_list(game->map->map[i], SPRITE_OBJ))
			add_sprite(game, i, game->map->map[i]);
		i++;
	}
}
