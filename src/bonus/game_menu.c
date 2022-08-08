/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:55:55 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/07 20:37:41 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

unsigned int	get_menu(t_cub3d *game, int x, int y)
{
	char			*pixel;
	unsigned int	color;

	pixel = game->menu_map->data;
	color = *(unsigned int *)(pixel + \
		get_byte_offset(game->menu_map, x, y - 477));
	return (color);
}

void	game_menu(t_cub3d *game, int x, int y)
{
	unsigned int	color;

	color = get_menu(game, x, y);
	if (color == MENU_OFF)
		game->menu = OFF;
	if (color == MENU_INV)
		game->menu = INV;
	if (color == MENU_QUEST)
		game->menu = QUEST;
	if (color == MENU_NUKED)
		game->menu = NUKED;
	if (color == MENU_MAP)
		game->menu = MAP;
	if (color == MENU_CHAR)
		game->menu = CHAR;
	if (color == MENU_PIP)
		game->menu = PIP;
}
