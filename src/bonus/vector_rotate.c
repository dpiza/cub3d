/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:33:20 by hde-camp          #+#    #+#             */
/*   Updated: 2022/08/07 20:41:32 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	rotate_vector(float sin, float cos, t_point *vector)
{
	t_point	x_y;

	x_y.x = (*vector).x;
	x_y.y = (*vector).y;
	(*vector).x = x_y.x * cos - x_y.y * sin;
	(*vector).y = x_y.x * sin + x_y.y * cos;
}
