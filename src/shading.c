/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:38:08 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/27 18:55:39 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	color_shade(float distance, unsigned int *pixel)
{
	unsigned char	color[3];
	float			factor;
	int				max_distance;

	max_distance = 20;
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
