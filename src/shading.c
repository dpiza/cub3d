/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:38:08 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/24 19:56:56 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	color_shade(float distance, unsigned int *pixel)
{
	unsigned char	color[3];
	float			factor;
	float			max_distance;

	max_distance = 20;
	factor = 1 - (distance / max_distance);
	if (distance > max_distance)
		factor = 0;
	color[0] = (*pixel >> 16);
	color[0] *= factor;
	color[1] = (*pixel >> 8);
	color[1] *= factor;
	color[2] = (*pixel);
	color[2] *= factor;
	*pixel = color[0] << 16 | color[1] << 8 | color[2];
}
