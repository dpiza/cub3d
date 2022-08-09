/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:38:46 by hde-camp          #+#    #+#             */
/*   Updated: 2022/08/09 12:34:23 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <libft.h>
# include <mlx.h>
# include <time.h>

/*
** Used in Get Next Line
*/
# define BUFFER_SIZE 32
# define OPEN_MAX 256

/*
** Colors used to map the clicks in the menu bar
*/
# define MENU_OFF	0x00ff0000
# define MENU_INV	0x009000ff
# define MENU_QUEST	0x00ff00ea
# define MENU_NUKED	0x00ffcd00
# define MENU_MAP	0x000000ff
# define MENU_CHAR	0x0000ff00
# define MENU_PIP	0x0000f0ff

/*
** Constants used for the projection calculation
*/
# define TO_DEGREE		57.296
# define MM_PPS			5
# define W_WIDTH 		800
# define W_HEIGHT 		600
# define FOV			75
# define MOVEMENT_STEP	0.15
# define ROTATE_SPEED	0.1
# define ANIMATION_CICLE 5
# define DEFAULT_HEIGHT	480

/*
** String patterns used for map parsing, minimap and actions
*/
# define MAP_LINE			"120DOBJKLXCNSEW \n"
# define MAP_ALLOWED 		"120DOBJKLXCNSEW "
# define MAP_INSIDE_OBJ		"120DOBJKLXCNSEW"
# define MAP_OBJ_NO_WALL	"0DOBJKLXCNSEW"
# define MAP_PLAYER_DIR		"NSEW"
# define MAP_COLLISION		"12DBJKL"
# define MINIMAP_DOOR		"DOB"
# define PCS				"JKL"
# define TEXTURE_DOOR		"DB"
# define SPRITE_OBJ			"XC"
# define INTER_OBJ			"DOJKLC"
# define MAP_OBSTACLE		"12DBJKLC"
# define SHOOTING_OBST		"12DBJKLXC"

/*
** Colors used in the minimap
*/
# define TRANSPARENCY		4278190080
# define SHADOW				0x001C1C1D
# define MM_DOOR			0x009f7315
# define MM_DOOR_SHADOW		0x005c4003
# define MM_WALL			0x003cf800
# define MM_WALL_SHADOW		0x00154b03
# define MM_EMPTY			0x001c1c1c
# define MM_EMPTY_SHADOW	0x001c1c1c
# define MM_FLOOR			0x001c1c1c
# define MM_FLOOR_SHADOW	0x000e0e0e
# define MM_OTHERS			0x001c1c1c
# define MM_OTHERS_SHADOW	0x001c1c1c
# define MM_PLAYER			0x00fc0000
# define PLAYER_RAYS		0x00006c00
# define PLAYER_RAYS_SHADOW	0x00004100

/*
** Keycodes used for hooks
*/
# define ESC				0xff1b
# define W_KEY				0x0077
# define A_KEY				0x0061
# define S_KEY				0x0073
# define D_KEY				0x0064
# define E_KEY				0x0065
# define R_KEY				0x0072
# define LEFT_ARROW_KEY		0xff51
# define UP_ARROW_KEY		0xff52
# define RIGHT_ARROW_KEY	0xff53
# define DOWN_ARROW_KEY		0xff54
# define LEFT_CLICK			1
# define RIGHT_CLICK		3

typedef struct s_map			t_map;
typedef struct s_strmap			t_strmap;
typedef struct s_mlx			t_mlx;
typedef struct s_mlx_img		t_mlx_img;
typedef struct s_cub3d			t_cub3d;
typedef struct s_point			t_point;
typedef struct s_player			t_player;
typedef struct s_int_point		t_int_point;
typedef struct s_collision		t_collision;
typedef struct s_dda			t_dda;
typedef struct s_wall_data		t_wall_data;
typedef struct s_texture		t_texture;
typedef struct s_sprite_list	t_sprite_list;
typedef struct s_sprite			t_sprite;
typedef struct s_quest			t_quest;

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

enum e_quest_step{
	DEFAULT = 0,
	CODESWORTH = 1,
	FOUND_DOOR = 2,
	FOUND_KEYS = 3,
	FINISH = 4
};

enum e_bar_screen{
	OFF = 0,
	INV = 1,
	QUEST = 2,
	NUKED = 3,
	MAP = 4,
	CHAR = 5,
	PIP = 6
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
	char	map_obj;
};

struct s_dda
{
	t_point		s_dist;
	t_point		delta;
	t_int_point	steps;
	t_int_point	map;
	float		w_dist;
	int			side;
	char		map_obj;
};

struct s_sprite
{
	t_mlx_img		*texture;
	t_point			pos;
	t_int_point		render_pos;
	float			distance;
	int				height;
	int				width;
	int				map_obj;
	int				enabled;
	int				shot;
	int				alive;
	int				expire;
	int				aggro;
	int				tick;
};

struct s_sprite_list
{
	t_sprite		*sprite;
	t_sprite_list	*next;
};

struct s_quest
{
	int		key_one;
	int		key_two;
	int		key_three;
	int		quest_step;
};

struct s_player
{
	t_point		pos;
	t_point		dir;
	float		angle;
	int			n_rays;
	t_point		*rays;
	t_collision	*collisions;
	t_point		fov_vec[2];
	char		aimed_obj;
	int			firing;
	int			ammo;
	int			left_click;
	int			right_click;
	int			in_conversation;
	int			notify;
	t_cub3d		*game;
	t_quest		quest;
	int			health;
	int			damaged;
};

struct s_texture
{
	t_mlx_img		*no;
	t_mlx_img		*so;
	t_mlx_img		*we;
	t_mlx_img		*ea;
	t_mlx_img		*door;
	t_mlx_img		*pc;
	t_mlx_img		*exit;
	t_mlx_img		*bar;
	t_mlx_img		*pressed_bar;
	t_mlx_img		*bar_screen;
	t_mlx_img		*inv0;
	t_mlx_img		*inv1;
	t_mlx_img		*inv2;
	t_mlx_img		*inv3;
	t_mlx_img		*character;
	t_mlx_img		*pip;
	t_mlx_img		*quest;
	t_mlx_img		*q1;
	t_mlx_img		*q2;
	t_mlx_img		*q3;
	t_mlx_img		*notif_key;
	t_mlx_img		*notif_door;
	t_mlx_img		*conversation;
	t_mlx_img		*action_open;
	t_mlx_img		*action_half;
	t_mlx_img		*action_closed;
	t_mlx_img		*action_denied;
	t_mlx_img		*weapon;
	t_mlx_img		*weapon_fire;
	t_mlx_img		*crosshair;
	t_mlx_img		*scor01;
	t_mlx_img		*scor02;
	t_mlx_img		*scor03;
	t_mlx_img		*scor16;
	t_mlx_img		*scor17;
	t_mlx_img		*scor18;
	t_mlx_img		*scor19;
	t_mlx_img		*scor20;
	t_mlx_img		*cods00;
	t_mlx_img		*cods01;
	t_mlx_img		*standby;
	t_mlx_img		*nuk3d;
	t_mlx_img		*dmg;
};

struct s_cub3d
{
	t_mlx			*mlx;
	t_strmap		*map;
	t_map			*s_map;
	t_mlx_img		*projection;
	t_mlx_img		*menu_map;
	t_texture		texture;
	unsigned int	floor;
	unsigned int	ceilling;
	struct s_player	player;
	t_int_point		mouse_pos;
	int				menu;
	int				tick;
	t_sprite_list	*sprite_list;
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

/*
** Utility functions
*/
char			*get_next_line(int fd);
int				get_byte_offset(t_mlx_img *img, int x, int y);
void			*get_pixel_address(t_mlx_img *img, int x, int y);
t_point			get_obj_pos(t_cub3d *game, int index);
char			get_map_obj(t_cub3d *game, float x, float y);
void			get_aimed_object(t_cub3d *game);
unsigned int	get_texture_pixel(t_mlx_img *img, float column, float line);
int				is_in_list(char c, char *list);
void			rotate_vector(float sin, float cos, t_point *vector);
t_point			sum_vectors(t_point *v_one, t_point *v_two);
t_point			subtract_vector(t_point *v_one, t_point *v_two);
float			vector_size(t_point *vector);
void			multiply_vector_by_n(float n, t_point *vector);
t_point			normalize_vector(t_point vector);
t_mlx_img		*new_blank_img(t_mlx *mlx, int width, int height);
void			override_images(t_mlx_img *dst, t_mlx_img *src, int x, int y);
void			override_minimap(t_mlx_img *dst, t_mlx_img *src, int x, int y);
void			override_btn(t_cub3d *game, int x, int y, unsigned int color);
void			color_shade(float distance, unsigned int *pixel);
t_mlx_img		*load_texture(t_cub3d *game, char *filename);
void			destroy_img(t_mlx_img *mlx_img);

/*
** Map parsing
*/
t_map			*load_map(const char *path);
void			load_strmap(t_strmap *strmap, t_map *map);
void			eval_map_rules(t_map *map, t_strmap *strmap);
void			eval_map(t_map *map);
void			map_integrity(t_map *map);
int				is_map_allowed_character(char c);
int				is_map_first_char(char c);
unsigned char	get_char_at(t_strmap *map, int x, int y);
void			eval_configs(t_map *map);
t_strmap		*new_strmap(void);
char			**get_map_first_line(t_map *map);
char			**get_map_last_line(char **first_line);
void			print_map_error(t_map *map);
void			destroy_strmap(t_strmap *strmap);
int				is_valid_map_line(char *line);
int				is_valid_texture_line(char *line, t_map *map);
int				is_valid_color_line(char *line);
int				get_map_max_len(char **first_line, int n_lines);
int				is_empty_line(char *line);
void			free_t_map(t_map *map);
char			*get_path(char *line);
void			eval_player_count(t_map *map, t_strmap *strmap);
int				is_xpm(char *path);

/*
** Hooks and actions
*/
int				mouse_click(int k, int x, int y, t_cub3d *game);
int				mouse_release(int k, int x, int y, t_cub3d *game);
int				mouse_movement(int x, int y, t_cub3d *game);
int				key_hook(int k, t_cub3d *game);
void			rotate_player(t_cub3d *game, float direction);
void			move_left(t_cub3d *game);
void			move_right(t_cub3d *game);
void			move_forward(t_cub3d *game);
void			move_backward(t_cub3d *game);
void			use(t_cub3d *game);
void			reload(t_cub3d *game);
void			fire(t_cub3d *game);

/*
** Projection
*/
void			set_fov_vectors(t_cub3d *game);
t_point			axis_collision(t_point pos, t_point norm_dir, float x_factor);
void			bresenham_line(t_mlx_img *img, t_int_point src, \
					t_int_point dst, unsigned int color);
t_dda			initialize_dda_values(t_cub3d *game, t_point norm_dir);
void			set_collisions(t_cub3d *game);
t_collision		get_collision(t_cub3d *game, t_point norm_dir);
t_collision		ret_collision_result(t_cub3d *game, t_point *norm_dir, \
					t_dda dda);
void			color_shade_ceiling(t_int_point *position, unsigned int *pixel);
void			build_projection(t_cub3d *game);
void			print_projection(t_cub3d *game);

/*
** Game execution
*/
int				init_game_state(t_cub3d *game);
t_cub3d			*load_game(t_map *map);
void			load_player(t_cub3d *game, t_player *player);
void			load_assets(t_cub3d *game);
void			build_map(t_cub3d *game);
int				game_loop(t_cub3d *game);
void			game_run(t_cub3d *game);
void			gracefull_shutdown(t_cub3d *game);
void			destroy_textures(t_cub3d *game);

/*
** HUD
*/
void			load_hud_assets(t_cub3d *game);
void			print_map(t_cub3d *game);
void			print_square(t_mlx_img *img, unsigned int *dest_origin, \
					int sqr_size, unsigned int color);
void			print_player_in_map(t_cub3d *game);
void			flickering(t_cub3d *game, t_int_point *point);
void			print_bar(t_cub3d *game);
void			print_bar_screen(t_cub3d *game);
void			print_inventory(t_cub3d *game);
void			print_quest(t_cub3d *game);
void			print_char(t_cub3d *game);
void			print_pip(t_cub3d *game);
void			print_stats(t_cub3d *game);
void			print_nuk3d(t_cub3d *game);
void			print_conversation(t_cub3d *game);
void			print_action_bar(t_cub3d *game);
void			print_weapon(t_cub3d *game);
void			print_firing_weapon(t_cub3d *game);
void			print_crosshair(t_cub3d *game);
void			print_damage(t_cub3d *game);
void			print_notification(t_cub3d *game);
unsigned int	get_menu(t_cub3d *game, int x, int y);
void			game_menu(t_cub3d *game, int x, int y);
void			stand_by(t_cub3d *game);
void			game_over(t_cub3d *game);

/*
** Sprites
*/
void			get_map_sprites(t_cub3d *game, t_strmap *str_map);
void			update_sprites_distance(t_cub3d *game);
void			sort_sprite_list(t_cub3d *game);
void			add_sprite(t_cub3d *game, int loc, char map_obj);
t_collision		get_sprite_collision(t_cub3d *game);
void			print_sprite_list(t_cub3d *game);
t_mlx_img		*get_scorched_texture(t_cub3d *game, t_sprite *sprite);
t_mlx_img		*get_cods_texture(t_cub3d *game, t_sprite *sprite);
void			damage_player(t_cub3d *game, t_sprite *sprite);
void			move_closer(t_cub3d *game, t_sprite *sprite);

#endif
