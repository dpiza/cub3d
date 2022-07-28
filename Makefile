CC	=	cc
CFLAGS = -Wall -Wextra -Werror -g

NAME 		= cub3D

SRC_D		=	src
OBJ_D		=	obj
INC_D		=	includes

LIBS		=	-L./libft -lft -lmlx -lXext -lX11 -lm

RAW_H		=	cub3d.h \
				libft.h

RAW_C		=	main.c \
				get_next_line.c \
				parser_load_map.c \
				parser_eval_map.c \
				parser_map_integrity.c \
				parser_eval_map_char.c \
				parser_eval_map_rules.c \
				parser_eval_assets.c \
				parser_create_strmap.c \
				parser_map_pointers.c \
				parser_line_checkers.c \
				hooks.c \
				print_map.c \
				get_img_offset.c \
				print_square.c \
				load_game.c \
				load_player.c \
				print_player_in_map.c \
				image_creation.c \
				build_minimap.c \
				images_override.c \
				vector_rotate.c \
				vector_multiply.c \
				vectors_sum.c \
				vectors_subtract.c \
				vector_size.c \
				bresenham_plot.c \
				vector_normalize.c \
				vector_collision.c \
				get_map_obj.c \
				build_projection.c \
				print_bar.c \
				print_weapon.c \
				load_assets.c \
				images_shading.c \
				print_projection.c \
				player_movement.c \
				get_collision.c \
				player_action.c

SRC			=	$(addprefix $(SRC_D)/,$(RAW_C))
OBJ			=	$(addprefix $(OBJ_D)/,$(RAW_C:.c=.o))
INCLUDES	=	$(addprefix $(INC_D)/,$(RAW_H))

.PHONY: clean fclean

$(NAME): $(OBJ) $(INCLUDES) 
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

$(OBJ_D)/%.o : $(SRC_D)/%.c ./libft/libft.a
	mkdir -p $(OBJ_D)
	$(CC) $(CFLAGS) -c $< -I $(INC_D) -o $@

all:	$(NAME)

clean:
	$(RM) $(OBJ)
	@make clean -C ./libft

fclean:	clean
	$(RM) $(NAME)
	@make fclean -C ./libft

re: fclean all

./libft/libft.a:
	@make -C ./libft --no-print-directory

bonus:
