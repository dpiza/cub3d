/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_hud_assets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:10:33 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/07 20:38:56 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	load_bar(t_cub3d *game)
{
	game->menu_map = load_texture(game, "./textures/hud/bar/menu_map.xpm");
	game->texture.bar = load_texture(game, "./textures/hud/bar/bar.xpm");
	game->texture.pressed_bar = load_texture(game, \
		"./textures/hud/bar/pressed_bar.xpm");
	game->texture.action_open = load_texture(game, \
		"./textures/hud/bar/action_open.xpm");
	game->texture.action_half = load_texture(game, \
		"./textures/hud/bar/action_half.xpm");
	game->texture.action_closed = load_texture(game, \
		"./textures/hud/bar/action_closed.xpm");
	game->texture.action_denied = load_texture(game, \
		"./textures/hud/bar/action_denied.xpm");
}

void	load_bar_screen(t_cub3d *game)
{
	game->texture.bar_screen = load_texture(game, \
		"./textures/hud/bar/bar_screen.xpm");
	game->texture.character = load_texture(game, \
		"./textures/hud/bar/char.xpm");
	game->texture.pip = load_texture(game, "./textures/hud/bar/pip.xpm");
	game->texture.inv0 = load_texture(game, "./textures/hud/bar/inv0.xpm");
	game->texture.inv1 = load_texture(game, "./textures/hud/bar/inv1.xpm");
	game->texture.inv2 = load_texture(game, "./textures/hud/bar/inv2.xpm");
	game->texture.inv3 = load_texture(game, "./textures/hud/bar/inv3.xpm");
	game->texture.quest = load_texture(game, "./textures/hud/bar/quest.xpm");
	game->texture.q1 = load_texture(game, "./textures/hud/bar/q1.xpm");
	game->texture.q2 = load_texture(game, "./textures/hud/bar/q2.xpm");
	game->texture.q3 = load_texture(game, "./textures/hud/bar/q3.xpm");
	game->texture.nuk3d = load_texture(game, \
		"./textures/hud/bar/nuk3d.xpm");
	game->texture.conversation = load_texture(game, \
		"./textures/hud/bar/conversation.xpm");
}

void	load_weapon_crosshair(t_cub3d *game)
{
	game->texture.crosshair = load_texture(game, \
		"./textures/hud/crosshair.xpm");
	game->texture.weapon = load_texture(game, \
		"./textures/weapon/weapon.xpm");
	game->texture.weapon_fire = load_texture(game, \
		"./textures/weapon/weapon_f.xpm");
}

void	load_notifications(t_cub3d *game)
{
	game->texture.notif_key = load_texture(game, \
		"./textures/hud/bar/notif_key.xpm");
	game->texture.notif_door = load_texture(game, \
		"./textures/hud/bar/notif_door.xpm");
}

void	load_hud_assets(t_cub3d *game)
{
	load_bar(game);
	load_bar_screen(game);
	load_weapon_crosshair(game);
	load_notifications(game);
}
