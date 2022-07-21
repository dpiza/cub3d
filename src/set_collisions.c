/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_collisions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:24:47 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/21 13:30:57 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	set_collisions(t_cub3d	*game)
{
	int	n_rays;

	n_rays = 0;
	while (n_rays < game->player.n_rays)
	{
		game->player.collisions[n_rays] = get_collision(game, game->player.rays[n_rays]);
		n_rays++;
	}
}
