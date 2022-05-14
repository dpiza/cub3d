/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player_in_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:07:08 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/14 00:30:54 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	print_player_int_map(t_cub3d *game)
{
	//get player position (in_map ->done game->player->pos)
	//get map 0,0 screen position DONE
	//get map pps DONE
	//create a conversion between player_x_y and screen x_y
	
	int	initial_offset;
	int	player_offset;
	//int	p_x;
	//int	p_y;

	initial_offset = get_byte_offset(game->mlx->img, game->map->pos.x, game->map->pos.y) / 4;
	//p_x = game->player.pos.x * game->map->minimap_pps;
	//p_y = game->player.pos.y * game->map->minimap_pps;
	//player_offset = get_byte_offset(game->mlx->img, p_x, p_y) / 8 + initial_offset;
	player_offset = initial_offset;
	player_offset += game->map->minimap_pps * game->player.pos.x;//add offset of columns
	player_offset += game->map->minimap_pps * (game->mlx->img->line_size / 4) * game->player.pos.y;

	print_square(game->mlx->img, &((unsigned int *)game->mlx->img->data)[player_offset], 4, 0xff66ff33);
	/*
	((unsigned int *)game->mlx->img->data)[player_offset] = 0xff66ff33;
	((unsigned int *)game->mlx->img->data)[player_offset + 1] = 0xff66ff33;
	((unsigned int *)game->mlx->img->data)[player_offset + 2] = 0xff66ff33;
	((unsigned int *)game->mlx->img->data)[player_offset + 3] = 0xff66ff33;

	((unsigned int *)game->mlx->img->data)[player_offset + (game->mlx->img->line_size / 4)] = 0xff66ff33;
	((unsigned int *)game->mlx->img->data)[player_offset + (game->mlx->img->line_size / 4) + 1] = 0xff66ff33;
	((unsigned int *)game->mlx->img->data)[player_offset + (game->mlx->img->line_size / 4) + 2] = 0xff66ff33;
	((unsigned int *)game->mlx->img->data)[player_offset + (game->mlx->img->line_size / 4) + 3] = 0xff66ff33;

	((unsigned int *)game->mlx->img->data)[player_offset + 2*(game->mlx->img->line_size / 4)] = 0xff66ff33;
	((unsigned int *)game->mlx->img->data)[player_offset + 2*(game->mlx->img->line_size / 4) + 1] = 0xff66ff33;
	((unsigned int *)game->mlx->img->data)[player_offset + 2*(game->mlx->img->line_size / 4) + 2] = 0xff66ff33;
	((unsigned int *)game->mlx->img->data)[player_offset + 2*(game->mlx->img->line_size / 4) + 3] = 0xff66ff33;
	
	((unsigned int *)game->mlx->img->data)[player_offset + 3*(game->mlx->img->line_size / 4)] = 0xff66ff33;
	((unsigned int *)game->mlx->img->data)[player_offset + 3*(game->mlx->img->line_size / 4) + 1] = 0xff66ff33;
	((unsigned int *)game->mlx->img->data)[player_offset + 3*(game->mlx->img->line_size / 4) + 2] = 0xff66ff33;
	((unsigned int *)game->mlx->img->data)[player_offset + 3*(game->mlx->img->line_size / 4) + 3] = 0xff66ff33;
	*/
}