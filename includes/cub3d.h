/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:38:46 by hde-camp          #+#    #+#             */
/*   Updated: 2022/08/02 20:49:02 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <libft.h>
# include <mlx.h>
# include <limits.h>

# define BUFFER_SIZE 32
# define OPEN_MAX 256

# define MM_PPS		5

# define W_WIDTH 		800
# define W_HEIGHT 		600
# define FOV				75
# define TRANSPARENCY	4278190080

# define MOVEMENT_STEP	0.1

# define SHADOW				0x001C1C1D

# define MM_WALL				0x003cf800
# define MM_WALL_SHADOW		0x00154b03

# define MM_EMPTY			0x001c1c1c
# define MM_EMPTY_SHADOW		0x001c1c1c

# define MM_FLOOR			0x001c1c1c
# define MM_FLOOR_SHADOW		0x000e0e0e

# define MM_OTHERS			0x001c1c1c
# define MM_OTHERS_SHADOW	0x001c1c1c

# define MM_PLAYER			0x00fc0000
# define PLAYER_RAYS			0x00006c00
# define PLAYER_RAYS_SHADOW	0x00004100

typedef struct s_map		t_map;
typedef struct s_strmap		t_strmap;
typedef struct s_mlx		t_mlx;
typedef struct s_mlx_img	t_mlx_img;
typedef struct s_cub3d		t_cub3d;
typedef struct s_point		t_point;
typedef struct s_player		t_player;
typedef struct s_int_point	t_int_point;
typedef struct s_collision	t_collision;
typedef struct s_dda		t_dda;
typedef struct s_wall_data	t_wall_data;

enum e_map_status{
	OK = 0,
	NO_MAP = 0b00000001,
	MISSING_CONFIGURATION = 0b00000010,
	INVALID_CHARACTER = 0b00000100,
	GARBAGE_LINES = 0b00001000,
	MAP_TOO_SHORT = 0b00010000,
	MAP_NOT_WALLED = 0b00100000,
	DUPLICATED_PARAMETER = 0b01000000,
	PLAYER_COUNT = 0b10000000
};

enum	e_wall_side{
	NORTH = 0,
	EAST = 1,
	SOUTH = 2,
	WEST = 3,
	NA = 4
};

struct s_wall_data
{
	float	height;
	int		top;
	int		bottom;
};

struct s_point
{
	float	x;
	float	y;
};

struct s_int_point
{
	int	x;
	int	y;
};

struct s_collision
{
	t_point	point;
	float	distance;
	float	perp_distance;
	int		side;
};

struct s_dda
{
	t_point		s_dist;
	t_point		delta;
	t_int_point	steps;
	t_int_point	map;
	float		w_dist;
	int			side;
};

struct s_player
{
	t_point		pos;
	t_point		dir;
	int			n_rays;
	t_point		*rays;
	t_collision	*collisions;
	t_point		fov_vec[2];
	int			firing;
	int			ammo;
	int			left_click;
	t_cub3d		*game;
};

struct s_cub3d
{
	t_mlx			*mlx;
	t_strmap		*map;
	t_map			*s_map;
	t_mlx_img		*projection;
	t_mlx_img		*texture_no;
	t_mlx_img		*texture_so;
	t_mlx_img		*texture_we;
	t_mlx_img		*texture_ea;
	t_mlx_img		*bar;
	t_mlx_img		*bar_screen;
	t_mlx_img		*weapon;
	t_mlx_img		*weapon_fire;
	t_mlx_img		*crosshair;
	unsigned int	floor;
	unsigned int	ceilling;
	struct s_player	player;
	t_int_point		mouse_pos;
	int				tick;
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

struct	s_map
{
	char				**lines;
	char				*no_path;
	char				*so_path;
	char				*we_path;
	char				*ea_path;
	unsigned char		floor_c[3];
	unsigned char		ceilling_c[3];
	enum e_map_status	status;
};

struct s_strmap
{
	char		*map;
	int			columns;
	int			lines;
	t_mlx_img	*minimap;
	t_int_point	pos;
};

char			*get_next_line(int fd);
t_map			*load_map(const char *path);
void			eval_map(t_map	*map);
void			map_integrity(t_map *map);
int				is_map_allowed_character(char c);
int				is_map_first_char(char c);
unsigned char	get_char_at(t_strmap *map, int x, int y);
void			eval_map_rules(t_map *map, t_strmap *strmap);
void			eval_configs(t_map *map);
t_strmap		*new_strmap(void);
void			load_strmap(t_strmap *strmap, t_map *map);
char			**get_map_first_line(t_map	*map);
char			**get_map_last_line(char **first_line);
void			print_map_error(t_map *map);
void			destroy_strmap(t_strmap *strmap);
int				is_valid_map_line(char *line);
int				is_valid_texture_line(char *line, t_map	*map);
int				is_valid_color_line(char *line);
int				get_map_max_len(char **first_line, int n_lines);
int				is_empty_line(char *line);
void			free_t_map(t_map *map);
char			*get_path(char *line);
int				mouse_hook(int k, int x, int y, t_cub3d *game);
int				mouse_release(int k, int x, int y, t_cub3d *game);
int				mouse_movement_hook(int x, int y, t_cub3d *game);
int				key_hook(int k, t_cub3d *game);
void			rotate_player(t_cub3d *game, float direction);
void			gracefull_shutdown(t_cub3d	*game);
void			print_map(t_cub3d *game);
int				get_byte_offset(t_mlx_img	*img, int x, int y);
void			*get_pixel_address(t_mlx_img	*img, int x, int y);
void			print_square(t_mlx_img	*img, unsigned int *dest_origin, \
					int sqr_size, unsigned int color);
void			load_player(t_cub3d	*game, t_player	*player);
t_cub3d			*load_game(t_map	*map);
int				init_game_state(t_cub3d *game);
t_mlx_img		*new_blank_img(t_mlx	*mlx, int width, int height);
void			build_map(t_cub3d *game);
void			print_player_int_map(t_cub3d *game);
void			override_images(t_mlx_img *dst, t_mlx_img *src, int x, int y);
void			override_minimap(t_mlx_img *dst, t_mlx_img *src, int x, int y);
void			rotate_vector_old(float angle, t_point *vector);
void			rotate_vector(float sin, float cos, t_point *vector);
t_point			sum_vectors(t_point *v_one, t_point *v_two);
t_point			subtract_vector(t_point *v_one, t_point *v_two);
float			vector_size(t_point *vector);
void			bresenham_line(t_mlx_img *img, t_int_point src, \
					t_int_point dst, unsigned int color);
void			multiply_vector_by_n(float n, t_point *vector);
void			set_fov_vectors(t_cub3d *game);
t_point			normalize_vector(t_point	vector);
t_collision		get_collision(t_cub3d *game, t_point norm_dir);
void			set_collisions(t_cub3d	*game);
char			get_map_obj(t_cub3d *game, float x, float y);
int				game_loop(t_cub3d *game);
void			load_assets(t_cub3d *game);
void			build_projection(t_cub3d *game);
void			color_shade(float distance, unsigned int *pixel);
void			print_projection(t_cub3d *game);
void			print_bar(t_cub3d *game);
void			print_bar_screen(t_cub3d *game);
void			print_weapon(t_cub3d *game);
void			print_firing_weapon(t_cub3d *game);
void			print_crosshair(t_cub3d *game);
void			destroy_img(t_mlx_img *mlx_img);
void			rotate_player(t_cub3d *game, float direction);
void			move_left(t_cub3d *game);
void			move_right(t_cub3d *game);
void			move_forward(t_cub3d *game);
void			move_backward(t_cub3d *game);
t_collision		ret_collision_result(t_cub3d *game, t_point *norm_dir, \
					t_dda dda);
t_dda			initialize_dda_values(t_cub3d *game, t_point norm_dir);
void			reload(t_cub3d *game);
void			fire(t_cub3d *game);
void			print_stats(t_cub3d *game);
void			game_run(t_cub3d	*game);
void			eval_player_count(t_map	*map, t_strmap *strmap);

#endif
