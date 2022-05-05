/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:51:28 by hcduller          #+#    #+#             */
/*   Updated: 2022/05/05 17:43:16 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*p;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	p = ft_calloc(ft_strlen((const char *)s) + 1, sizeof(char));
	i = 0;
	if (p)
	{
		while (s[i])
		{
			p[i] = f(i, s[i]);
			i++;
		}
	}
	return (p);
}
