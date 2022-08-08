/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_shading.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:38:08 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/07 20:38:45 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	color_shade(float distance, unsigned int *pixel)
{
	unsigned char	color[3];
	float			factor;
	int				max_distance;

	max_distance = 10;
	if (distance > 2)
		distance -= 2;
	else
		return ;
	if (distance < max_distance)
	{
		factor = 1 - (distance / max_distance);
		color[0] = ((unsigned char)(*pixel >> 16)) * factor;
		color[1] = ((unsigned char)(*pixel >> 8)) * factor;
		color[2] = ((unsigned char)(*pixel)) * factor;
		*pixel = color[0] << 16 | color[1] << 8 | color[2];
	}
	else
		*pixel = 0;
}

void	color_shade_ceiling(t_int_point *position, unsigned int *pixel)
{
	unsigned char	color[3];
	float			factor;

	factor = 1;
	if (position->y < 240 && position->y > 30)
		factor = 1 - ((position->y - 30) / 210.0f);
	else if (position->y > 240)
		factor = 1 - ((420.0f - position->y) / 220);
	color[0] = ((unsigned char)(*pixel >> 16)) * factor;
	color[1] = ((unsigned char)(*pixel >> 8)) * factor;
	color[2] = ((unsigned char)(*pixel)) * factor;
	*pixel = color[0] << 16 | color[1] << 8 | color[2];
}
