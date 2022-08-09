/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 09:34:42 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/07 20:40:37 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	flickering(t_cub3d *game, t_int_point *point)
{
	static int	tickering;

	(void)game;
	if (tickering % 6 * ANIMATION_CICLE == 0)
		point->y++;
	else if (tickering % 12 * ANIMATION_CICLE == 0)
		point->y++;
	else if (tickering % 14 * ANIMATION_CICLE == 0)
		point->y--;
	else if (tickering % 16 * ANIMATION_CICLE == 0)
		point->y--;
	else if (tickering % 20 * ANIMATION_CICLE == 0)
		point->y = 600;
	tickering++;
	if (tickering > 100)
		tickering = 0;
}

void	print_char(t_cub3d *game)
{
	t_int_point	point;

	point.y = W_HEIGHT - game->texture.character->height;
	point.x = 0;
	flickering(game, &point);
	if (!game->player.in_conversation && game->menu == CHAR)
		override_images(game->mlx->img, game->texture.character, \
			point.x, point.y);
}

void	print_pip(t_cub3d *game)
{
	t_int_point	point;

	point.y = W_HEIGHT - game->texture.pip->height;
	point.x = 0;
	flickering(game, &point);
	if (!game->player.in_conversation && game->menu == PIP)
		override_images(game->mlx->img, game->texture.pip, point.x, point.y);
}

void	print_map(t_cub3d *game)
{
	t_int_point	point;

	point.x = game->map->pos.x;
	point.y = game->map->pos.y;
	flickering(game, &point);
	if (!game->player.in_conversation && game->menu == MAP)
		override_minimap(game->mlx->img, game->map->minimap, point.x, point.y);
}

void	print_quest(t_cub3d *game)
{
	t_int_point	point;

	point.y = W_HEIGHT - game->texture.quest->height;
	point.x = 0;
	flickering(game, &point);
	if (!game->player.in_conversation && game->menu == QUEST \
		&& game->player.quest.quest_step == CODESWORTH)
		override_images(game->mlx->img, game->texture.q1, point.x, point.y);
	else if (!game->player.in_conversation && game->menu == QUEST \
		&& game->player.quest.quest_step == FOUND_DOOR)
		override_images(game->mlx->img, game->texture.q2, point.x, point.y);
	else if (!game->player.in_conversation && game->menu == QUEST \
		&& game->player.quest.quest_step == FOUND_KEYS)
		override_images(game->mlx->img, game->texture.q3, point.x, point.y);
}
