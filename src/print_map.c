/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:46:00 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/18 18:48:58 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	print_map(t_cub3d *game)
{
	build_map_img(game);
	override_images(game->mlx->img, game->map->minimap, game->map->pos.x, game->map->pos.y);
}
