/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_projection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:02:33 by hde-camp          #+#    #+#             */
/*   Updated: 2022/08/07 20:40:45 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	print_projection(t_cub3d *game)
{
	override_images(game->mlx->img, game->projection, 0, 0);
}
