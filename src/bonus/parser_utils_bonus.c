/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 23:17:50 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/07 20:40:06 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

int	is_xpm(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 5)
		return (0);
	if (!ft_strncmp(path + len - 5, ".xpm", 4))
		return (1);
	return (0);
}
