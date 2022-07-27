/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 01:01:54 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/27 01:03:38 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	shot(t_cub3d *game)
{
	game->player.firing = 1;
}

int	mouse_movement_hook(int x, int y, t_cub3d *game)
{
	if (!game->player.left_click)
		return (0);
	if (x > game->mouse_pos.x)
		rotate_player(game, 1.0f);
	else
		rotate_player(game, -1.0f);
	game->mouse_pos.x = x;
	game->mouse_pos.y = y;
	return(0);
}

int	mouse_hook(int k, int x, int y, t_cub3d *game)
{
	(void)x;
	(void)y;
	if (k == 1)
		shot(game);
	if (k == 3)
		game->player.left_click = 1;
	game_loop(game);
	return (0);
}

int	mouse_release(int k, int x, int y, t_cub3d *game)
{
	(void)x;
	(void)y;
	if (k == 3)
		game->player.left_click = 0;
	game_loop(game);
	return (0);
}