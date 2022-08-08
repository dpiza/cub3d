/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:00:26 by hde-camp          #+#    #+#             */
/*   Updated: 2022/08/07 20:41:25 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	multiply_vector_by_n(float n, t_point *vector)
{
	(*vector).x = n * (*vector).x;
	(*vector).y = n * (*vector).y;
}
