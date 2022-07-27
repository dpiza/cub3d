/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:46:00 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/27 19:01:45 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	print_map(t_cub3d *game)
{
	int	x;
	int	y;

	x = game->map->pos.x;
	y = game->map->pos.y;
	override_minimap(game->mlx->img, game->map->minimap, x, y);
}
