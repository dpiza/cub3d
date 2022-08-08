/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_aimed_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:34:31 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/07 20:38:00 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	get_aimed_object(t_cub3d *game)
{
	t_point	use_pos;
	char	map_obj;

	use_pos.x = game->player.pos.x + game->player.dir.x;
	use_pos.y = game->player.pos.y + game->player.dir.y;
	map_obj = get_map_obj(game, use_pos.x, use_pos.y);
	game->player.aimed_obj = map_obj;
}
