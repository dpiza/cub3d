/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:38:46 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/10 13:05:54 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <libft.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct s_map		t_map;
typedef struct s_strmap		t_strmap;
typedef struct s_mlx		t_mlx;
typedef struct s_mlx_img	t_mlx_img;

enum e_map_status{
	OK = 0,
	NO_MAP = 0b00000001,
	PERIMETER_ERROR = 0b00000010,
	INVALID_CHARACTER = 0b00000100,
	GARBAGE_LINES = 0b00001000,
	MAP_TOO_SHORT = 0b00010000,
	MAP_NOT_WALLED = 0b00100000,
	DUPLICATED_PARAMETER = 0b01000000
};

struct	s_map
{
	char				**lines;
	char				*no_path;
	char				*so_path;
	char				*we_path;
	char				*ea_path;
	unsigned char		floor_c[3];
	unsigned char		ceiling_c[3];
	enum e_map_status	status;
};

struct s_strmap{
	char	*map;
	int		columns;
	int		lines;
};

struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_mlx_img	*img;
	int			width;
	int			height;
};

struct s_mlx_img
{
	t_mlx	*mlx;
	void	*img_ptr;
	void	*data;
	int		width;
	int		height;
	int		bpp;
	int		line_size;
	int		endian;
};

char		*get_next_line(int fd);
t_map		*load_map(const char *path);
void		eval_map(t_map	*map);
void		map_integrity(t_map *map);
int			is_map_allowed_character(char c);
int			is_map_first_char(char c);
void		eval_map_rules(t_map *map, t_strmap *strmap);
void		eval_assets(t_map *map);
t_strmap	*new_strmap(void);
void		load_strmap(t_strmap *strmap, t_map *map);
char		**get_map_first_line(t_map	*map);
char		**get_map_last_line(char **first_line);
void		print_map_error(t_map *map);
void		destroy_strmap(t_strmap *strmap);
int			is_valid_map_line(char *line);
int			is_valid_texture_line(char *line);
int			is_valid_color_line(char *line);
int			is_empty_line(char *line);
void		free_t_map(t_map *map);
char		*get_path(char *line);
int		key_hook(int k, t_mlx *mlx);

# define OPEN_MAX 256

#endif
