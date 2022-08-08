/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu_inventory.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:30:28 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/07 20:40:33 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

int	keys_count(t_cub3d *game)
{
	int	count;

	count = 0;
	if (game->player.quest.key_one == 1)
		count++;
	if (game->player.quest.key_two == 1)
		count++;
	if (game->player.quest.key_three == 1)
		count++;
	return (count);
}

void	print_inventory(t_cub3d *game)
{
	t_int_point	point;
	int			keys;

	keys = keys_count(game);
	point.y = W_HEIGHT - game->texture.inv0->height;
	point.x = 0;
	flickering(game, &point);
	if (game->player.in_conversation)
		return ;
	if (game->menu == INV)
	{
		if (keys == 0)
			override_images(game->mlx->img, game->texture.inv0, \
			point.x, point.y);
		else if (keys == 1)
			override_images(game->mlx->img, game->texture.inv1, \
			point.x, point.y);
		else if (keys == 2)
			override_images(game->mlx->img, game->texture.inv2, \
			point.x, point.y);
		else if (keys == 3)
			override_images(game->mlx->img, game->texture.inv3, \
			point.x, point.y);
	}
}

void	print_nuk3d(t_cub3d *game)
{
	t_int_point	point;

	point.y = W_HEIGHT - game->texture.nuk3d->height;
	point.x = 0;
	flickering(game, &point);
	if (!game->player.in_conversation
		&& game->menu == NUKED)
		override_images(game->mlx->img, game->texture.nuk3d, point.x, point.y);
	else if (game->player.in_conversation
		&& game->player.quest.quest_step == FINISH)
		override_images(game->mlx->img, game->texture.nuk3d, point.x, point.y);
}
