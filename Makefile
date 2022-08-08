CC	=	cc
CFLAGS = -Wall -Wextra -Werror -g

NAME 		= cub3D

INC 		=	includes
OBJ_D		=	obj
OBJ_D_BONUS	=	obj/bonus

SRC_D		=	src/mandatory
INC_D		=	includes/mandatory

SRC_D_BONUS	=	src/bonus
INC_D_BONUS	=	includes/bonus

LIBS		=	-L./libft -lft -lmlx -lXext -lX11 -lm

RAW_H		=	cub3d.h

RAW_H_BONUS	=	cub3d_bonus.h

LIBFT		=	libft.h

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
				vector_collision_bresenham.c \
				vector_normalize.c \
				vector_collision_dda.c \
				get_map_obj.c \
				build_projection.c \
				print_bar.c \
				print_weapon.c \
				load_assets.c \
				images_shading.c \
				print_projection.c \
				player_movement.c \
				get_collision.c \
				player_action.c \
				game_shutdown.c \
				game_run.c \
				parse_player_count.c \
				parser_eval_line.c

RAW_C_BONUS		=	main.c \
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
				parse_player_count.c \
				parser_utils.c \
				vector_rotate.c \
				vector_multiply.c \
				vectors_sum.c \
				vectors_subtract.c \
				vector_size.c \
				vector_collision_bresenham.c \
				vector_normalize.c \
				vector_collision_dda.c \
				image_creation.c \
				images_override.c \
				images_shading.c \
				get_img_offset.c \
				get_map_obj.c \
				get_aimed_object.c \
				get_map_sprites.c \
				get_collision.c \
				load_game.c \
				load_player.c \
				load_assets.c \
				load_hud_assets.c \
				build_minimap.c \
				build_projection.c \
				player_movement.c \
				player_action.c \
				player_action_weapon.c \
				game_run.c \
				game_menu.c \
				game_over.c \
				hooks.c \
				print_square.c \
				print_player_in_map.c \
				print_bar.c \
				print_menu.c \
				print_action.c \
				print_stats.c \
				print_weapon.c \
				print_sprites.c \
				print_conversation.c \
				print_menu_inventory.c \
				print_projection.c \
				sprite_list.c \
				sprite_movement.c \
				get_scorched_texture.c \
				get_cods_texture.c \
				game_shutdown.c \
				texture_destroy.c 

SRC			=	$(addprefix $(SRC_D)/,$(RAW_C))
OBJ			=	$(addprefix $(OBJ_D)/,$(RAW_C:.c=.o))
INCLUDES	=	$(addprefix $(INC_D)/,$(RAW_H))

SRC_BONUS		=	$(addprefix $(SRC_D_BONUS)/,$(RAW_C_BONUS))
OBJ_BONUS		=	$(addprefix $(OBJ_D_BONUS)/,$(RAW_C_BONUS:.c=.o))
INCLUDES_BONUS	=	$(addprefix $(INC_D_BONUS)/,$(RAW_H_BONUS))


$(NAME): $(OBJ) $(INCLUDES)
	@echo -n "Compiling $(NAME)... "
	@$(CC) $(OBJ) $(LIBS) -o $(NAME)
	@echo Done!

$(OBJ_D)/%.o : $(SRC_D)/%.c ./libft/libft.a
	@echo -n "Compiling $@... "
	@mkdir -p $(OBJ_D)
	@$(CC) $(CFLAGS) -c $< -I $(INC_D) -I $(INC) -o $@
	@echo Done!

bonus:  $(OBJ_BONUS) $(INCLUDES_BONUS)
	@echo -n "Compiling $(NAME)... "
	@$(CC) $(OBJ_BONUS) $(LIBS) -o $(NAME)
	@echo Done!

$(OBJ_D_BONUS)/%.o : $(SRC_D_BONUS)/%.c ./libft/libft.a
	@echo -n "Compiling $@... "
	@mkdir -p $(OBJ_D_BONUS)
	@$(CC) $(CFLAGS) -c $< -I $(INC_D_BONUS) -I $(INC) -o $@
	@echo Done!
	
all:	$(NAME)

clean:
	@echo -n "Cleaning... "
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_BONUS)
	@make clean --no-print-directory -C ./libft
	@echo Done!

fclean:	clean
	@$(RM) $(NAME)
	@make fclean --no-print-directory -C ./libft

re: fclean all

./libft/libft.a:
	@echo -n "Making LIBFT... "
	@make --no-print-directory -C ./libft
	@echo Done!

.PHONY: clean fclean re bonus