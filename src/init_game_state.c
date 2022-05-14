/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:43:33 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/12 23:43:56 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int		init_game_state(t_cub3d *game)
{
	game->mlx = ft_calloc(1, sizeof(t_mlx));
	game->mlx->mlx_ptr = mlx_init();
	if (game->mlx->mlx_ptr)
		return (1);
	return (0);
}
