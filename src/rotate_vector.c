/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:33:20 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/20 20:41:26 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	rotate_vector(float	angle, t_point *vector)
{
	t_point	x_y;

	x_y.x = (*vector).x;
	x_y.y = (*vector).y;
	(*vector).x = x_y.x * cosf(angle) - x_y.y * sinf(angle);
	(*vector).y = x_y.x * cosf(angle) + x_y.y * sinf(angle);
}
