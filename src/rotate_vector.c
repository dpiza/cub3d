/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:33:20 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/23 18:01:59 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	rotate_vector(float	angle, t_point *vector)
{
	t_point	x_y;
	float	cos;
	float	sin;

	x_y.x = (*vector).x;
	x_y.y = (*vector).y;
	cos = cosf(angle);
	sin = sinf(angle);
	(*vector).x = x_y.x * cos - x_y.y * sin;
	(*vector).y = x_y.x * sin + x_y.y * cos;
}
