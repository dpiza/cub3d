/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:26:46 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/07 20:38:25 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

char	*ft_return_line(char **save)
{
	char		*ret;
	char		*temp;
	int			n;

	if (!*save || **save == '\0')
		return (NULL);
	n = (int)((ft_strchr(*save, '\n')) - *save);
	if (ft_strchr(*save, '\n'))
	{
		ret = ft_substr(*save, 0, n + 1);
		temp = ft_substr(*save, n + 1, ft_strlen((const char *)*save));
		free (*save);
		*save = temp;
		if (**save != '\0')
			return (ret);
	}
	else
		ret = ft_strdup(*save);
	free (*save);
	*save = NULL;
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*temp;
	char		*buffer;
	static char	*save[OPEN_MAX];
	int			ret;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (NULL);
	buffer = (char *)malloc((1 + BUFFER_SIZE) * sizeof(char));
	if (!buffer)
		return (NULL);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		if (save[fd] == NULL)
			save[fd] = ft_strdup("");
		temp = ft_strjoin(save[fd], buffer);
		free (save[fd]);
		save[fd] = temp;
		if (ft_strchr(save[fd], '\n'))
			break ;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	free (buffer);
	return (ft_return_line(&save[fd]));
}
