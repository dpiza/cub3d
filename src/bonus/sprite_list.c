/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 23:10:51 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/07 20:41:05 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

t_sprite_list	*get_last_sprite(t_cub3d *game)
{
	t_sprite_list	*current;

	current = game->sprite_list;
	if (!current)
		return (NULL);
	while (current->next)
		current = current->next;
	return (current);
}

void	add_sprite(t_cub3d *game, int loc, char map_obj)
{
	t_sprite_list	*last_sprite;
	t_sprite_list	*new_item;
	t_point			pos;
	t_point			subtract_pos;

	new_item = ft_calloc(1, sizeof(t_sprite_list));
	new_item->sprite = ft_calloc(1, sizeof(t_sprite));
	new_item->sprite->map_obj = map_obj;
	new_item->sprite->alive = 1;
	new_item->sprite->enabled = 1;
	new_item->sprite->pos = get_obj_pos(game, loc);
	new_item->sprite->tick = 0;
	pos.x = new_item->sprite->pos.x;
	pos.y = new_item->sprite->pos.y;
	new_item->next = NULL;
	subtract_pos = subtract_vector(&game->player.pos, &pos);
	new_item->sprite->distance = sqrt(subtract_pos.x * subtract_pos.x + \
		subtract_pos.y * subtract_pos.y);
	last_sprite = get_last_sprite(game);
	if (!last_sprite)
		game->sprite_list = new_item;
	else
		last_sprite->next = new_item;
}

int	is_sorted_sprites(t_cub3d *game)
{
	t_sprite_list	*head;
	t_sprite_list	*current;

	head = game->sprite_list;
	if (!head)
		return (1);
	current = head->next;
	while (current)
	{
		if (head->sprite->distance < current->sprite->distance)
			return (0);
		head = current;
		current = current->next;
	}
	return (1);
}

void	sort_sprite_list(t_cub3d *game)
{
	t_sprite_list	*head;
	t_sprite_list	*current;
	t_sprite		*tmp;

	head = game->sprite_list;
	if (!head)
		return ;
	current = head->next;
	while (!is_sorted_sprites(game) && current)
	{
		if (current)
		{
			if (head->sprite->distance < current->sprite->distance)
			{
				tmp = head->sprite;
				head->sprite = current->sprite;
				current->sprite = tmp;
			}
			head = current;
			current = current->next;
		}
	}
}
