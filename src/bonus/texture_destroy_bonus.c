/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:02:48 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/07 20:41:13 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	destroy_collision_textures(t_cub3d *game)
{
	destroy_img(game->texture.no);
	destroy_img(game->texture.so);
	destroy_img(game->texture.we);
	destroy_img(game->texture.ea);
	destroy_img(game->texture.door);
	destroy_img(game->texture.pc);
	destroy_img(game->texture.exit);
}

void	destroy_bar_textures(t_cub3d *game)
{
	destroy_img(game->texture.bar);
	destroy_img(game->texture.pressed_bar);
	destroy_img(game->texture.bar_screen);
	destroy_img(game->texture.inv0);
	destroy_img(game->texture.inv1);
	destroy_img(game->texture.inv2);
	destroy_img(game->texture.inv3);
	destroy_img(game->texture.pip);
	destroy_img(game->texture.quest);
	destroy_img(game->texture.q1);
	destroy_img(game->texture.q2);
	destroy_img(game->texture.q3);
	destroy_img(game->texture.character);
	destroy_img(game->texture.conversation);
	destroy_img(game->texture.action_open);
	destroy_img(game->texture.action_half);
	destroy_img(game->texture.action_closed);
	destroy_img(game->texture.action_denied);
}

void	destroy_sprite_textures(t_cub3d *game)
{
	destroy_img(game->texture.scor01);
	destroy_img(game->texture.scor02);
	destroy_img(game->texture.scor03);
	destroy_img(game->texture.scor16);
	destroy_img(game->texture.scor17);
	destroy_img(game->texture.scor18);
	destroy_img(game->texture.scor19);
	destroy_img(game->texture.scor20);
	destroy_img(game->texture.cods00);
	destroy_img(game->texture.cods01);
}

void	destroy_textures(t_cub3d *game)
{
	destroy_collision_textures(game);
	destroy_bar_textures(game);
	destroy_sprite_textures(game);
	destroy_img(game->texture.notif_key);
	destroy_img(game->texture.notif_door);
	destroy_img(game->texture.crosshair);
	destroy_img(game->texture.weapon);
	destroy_img(game->texture.weapon_fire);
	destroy_img(game->texture.standby);
	destroy_img(game->texture.nuk3d);
	destroy_img(game->texture.dmg);
}
