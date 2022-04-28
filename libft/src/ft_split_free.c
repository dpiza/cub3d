/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:57:02 by rkochhan          #+#    #+#             */
/*   Updated: 2022/04/25 17:41:41 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

void	ft_split_free(char ***str_array)
{
	size_t	i;

	i = 0;
	while ((*str_array)[i])
	{
		ft_strdel(&((*str_array)[i]));
		i++;
	}
	free(*str_array);
	*str_array = NULL;
}
