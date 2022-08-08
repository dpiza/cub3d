/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:42:40 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/07 20:40:25 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	print_bar_screen(t_cub3d *game)
{
	int	dst_y;

	dst_y = W_HEIGHT - game->texture.bar_screen->height;
	override_images(game->mlx->img, game->texture.bar_screen, 0, dst_y);
}

void	print_bar_frame(t_cub3d *game)
{
	int	dst_y;

	dst_y = W_HEIGHT - game->texture.bar->height;
	override_images(game->mlx->img, game->texture.bar, 0, dst_y);
}

void	print_button(t_cub3d *game, unsigned int color)
{
	int	dst_y;

	dst_y = W_HEIGHT - game->texture.pressed_bar->height;
	override_btn(game, 0, dst_y, color);
}

void	print_pressed_button(t_cub3d *game)
{
	unsigned int	color;

	if (!game->player.left_click)
		return ;
	color = get_menu(game, game->mouse_pos.x, game->mouse_pos.y);
	if (color == MENU_OFF || color == MENU_INV || color == MENU_QUEST
		|| color == MENU_NUKED || color == MENU_MAP || color == MENU_CHAR
		|| color == MENU_PIP)
		print_button(game, color);
}

void	print_bar(t_cub3d *game)
{
	build_map(game);
	print_player_in_map(game);
	print_bar_screen(game);
	print_map(game);
	print_inventory(game);
	print_char(game);
	print_pip(game);
	print_quest(game);
	print_nuk3d(game);
	print_bar_frame(game);
	print_pressed_button(game);
	print_action_bar(game);
	print_conversation(game);
}
