/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:11:20 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/07 20:40:56 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	print_stats(t_cub3d *game)
{
	char	*hp;
	char	*ammo;

	hp = ft_itoa(game->player.health);
	ammo = ft_itoa(game->player.ammo);
	mlx_string_put(game->mlx->mlx_ptr, game->mlx->win_ptr, \
		602, 538, 0x003cf800, hp);
	mlx_string_put(game->mlx->mlx_ptr, game->mlx->win_ptr, \
		605, 583, 0x003cf800, ammo);
	free(hp);
	free(ammo);
}
