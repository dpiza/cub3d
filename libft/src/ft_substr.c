/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:23:18 by hcduller          #+#    #+#             */
/*   Updated: 2022/05/05 17:43:01 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static	size_t	smaller(size_t a, size_t b);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	nl;
	size_t	sl;
	char	*ptr;

	if (!s)
		return (NULL);
	i = 0;
	sl = ft_strlen((const char *)s);
	if (sl < start)
		return (ft_calloc(1, 1));
	sl = ft_strlen((const char *)&s[start]);
	nl = smaller(sl, len);
	ptr = ft_calloc(nl + 1, sizeof(char));
	if (ptr)
	{		
		while (i < len && s[start + i])
		{
			*(ptr + i) = s[start + i];
			i++;
		}
	}
	return (ptr);
}

size_t	smaller(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}
