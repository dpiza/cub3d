/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:55:47 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/28 18:57:28 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	reload(t_cub3d *game)
{
	if (game->player.firing == 0 && game->player.ammo == 0)
	{
		game->player.ammo = 15;
		game->player.firing = -12;
	}
}

void	fire(t_cub3d *game)
{
	if (game->player.firing == 0 && game->player.ammo > 0)
	{
		game->player.firing = 1;
		game->player.ammo--;
	}
}
