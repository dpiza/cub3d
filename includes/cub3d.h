/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:38:46 by hde-camp          #+#    #+#             */
/*   Updated: 2022/04/25 15:53:15 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <libft.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif


typedef struct s_map	t_map;

enum e_map_status{
	NOT_FOUND = 1,
	PERIMETER_ERROR = 2,
	INVALID_CHARACTER = 3,
	GARBAGE_LINES = 4
};

struct	s_map
{
	char	**lines;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	floor_c[3];
	char	ceiling_c[3];
	int		is_ok;
};

char	*get_next_line(int fd);
t_map	*load_map(const char *path);
void	eval_map(t_map	*map);
void	map_integrity(t_map *map);

# define OPEN_MAX 256

#endif
