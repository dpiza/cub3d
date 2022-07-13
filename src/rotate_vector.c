/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:33:20 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/12 21:36:28 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	rotate_vector_old(float	angle, t_point *vector)
{
	t_point	x_y;
	float	cos;
	float	sin;

	x_y.x = (*vector).x;
	x_y.y = (*vector).y;
	cos = cosf(angle);
	if (cos*cos < 0.00000001) //this ensures cos >= 0.0001 is rounded to zero
		cos = 0;
	sin = sinf(angle);
	if (sin*sin < 0.00000001)
		sin = 0;
	(*vector).x = x_y.x * cos - x_y.y * sin;
	(*vector).y = x_y.x * sin + x_y.y * cos;
}

void	rotate_vector_new(float sin, float cos, t_point *vector)
{
	t_point	x_y;

	x_y.x = (*vector).x;
	x_y.y = (*vector).y;
	(*vector).x = x_y.x * cos - x_y.y * sin;
	(*vector).y = x_y.x * sin + x_y.y * cos;
}
