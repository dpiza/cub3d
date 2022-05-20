/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_vector_by_n.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:00:26 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/20 20:41:18 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	multiply_vector_by_n(float	n, t_point	*vector)
{
	(*vector).x = n * (*vector).x;
	(*vector).y = n * (*vector).y;
}
