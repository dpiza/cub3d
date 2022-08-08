/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_vectors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:07:16 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/28 10:27:22 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_point	sum_vectors(t_point *v_one, t_point *v_two)
{
	t_point	new_vector;

	new_vector.x = v_one->x + v_two->x;
	new_vector.y = v_one->y + v_two->y;
	return (new_vector);
}
