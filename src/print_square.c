/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:40:28 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/12 15:42:05 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	print_square(t_mlx_img	*img, unsigned int *dest_origin, int sqr_size, unsigned int color)
{
	unsigned int	*dest;
	int	i[2];

	dest = dest_origin;
	i[0] = 0;
	while (i[0] < sqr_size)
	{
		i[1] = 0;
		while (i[1] < sqr_size)
		{
			if (i[0] && i[1])
				*dest = color;
			else
				*dest = 0x00ffffff;
			dest++;
			i[1]++;
		}
		dest += img->width - sqr_size;
		i[0]++;
	}
}
