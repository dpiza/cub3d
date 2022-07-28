/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:03:50 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/06 18:10:06 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_point	normalize_vector(t_point	vector)
{
	t_point	normalized;
	float	hipotenuse;
	float	factor;

	hipotenuse = sqrtf(vector.x * vector.x + vector.y * vector.y);
	factor = 1 / hipotenuse;
	normalized.x = vector.x * factor;
	normalized.y = vector.y * factor;
	return (normalized);
}
