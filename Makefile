CC	=	cc
CFLAGS = -Wall -Wextra -Werror -g

NAME 		= cub3D
NAME_BONUS	= cub3d_bonus

INC 		=	includes
OBJ_D		=	obj
OBJ_D_BONUS	=	obj

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
				load_assets.c \
				images_shading.c \
				print_projection.c \
				player_movement.c \
				get_collision.c \
				game_shutdown.c \
				game_run.c \
				parse_player_count.c \
				parser_eval_line.c

RAW_C_BONUS		=	main_bonus.c \
				get_next_line_bonus.c \
				parser_load_map_bonus.c \
				parser_eval_map_bonus.c \
				parser_map_integrity_bonus.c \
				parser_eval_map_char_bonus.c \
				parser_eval_map_rules_bonus.c \
				parser_eval_assets_bonus.c \
				parser_create_strmap_bonus.c \
				parser_map_pointers_bonus.c \
				parser_line_checkers_bonus.c \
				parse_player_count_bonus.c \
				parser_utils_bonus.c \
				vector_rotate_bonus.c \
				vector_multiply_bonus.c \
				vectors_sum_bonus.c \
				vectors_subtract_bonus.c \
				vector_size_bonus.c \
				vector_collision_bresenham_bonus.c \
				vector_normalize_bonus.c \
				vector_collision_dda_bonus.c \
				image_creation_bonus.c \
				images_override_bonus.c \
				images_shading_bonus.c \
				get_img_offset_bonus.c \
				get_map_obj_bonus.c \
				get_aimed_object_bonus.c \
				get_map_sprites_bonus.c \
				get_collision_bonus.c \
				load_game_bonus.c \
				load_player_bonus.c \
				load_assets_bonus.c \
				load_hud_assets_bonus.c \
				build_minimap_bonus.c \
				build_projection_bonus.c \
				player_movement_bonus.c \
				player_action_bonus.c \
				player_action_weapon_bonus.c \
				game_run_bonus.c \
				game_menu_bonus.c \
				game_over_bonus.c \
				hooks_bonus.c \
				print_square_bonus.c \
				print_player_in_map_bonus.c \
				print_bar_bonus.c \
				print_menu_bonus.c \
				print_action_bonus.c \
				print_stats_bonus.c \
				print_weapon_bonus.c \
				print_sprites_bonus.c \
				print_conversation_bonus.c \
				print_menu_inventory_bonus.c \
				print_projection_bonus.c \
				sprite_list_bonus.c \
				sprite_movement_bonus.c \
				get_scorched_texture_bonus.c \
				get_cods_texture_bonus.c \
				game_shutdown_bonus.c \
				texture_destroy_bonus.c 

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

bonus:  $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(INCLUDES_BONUS)
	@echo -n "Compiling $(NAME_BONUS)... "
	@$(CC) $(OBJ_BONUS) $(LIBS) -o $(NAME_BONUS)
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
	@$(RM) $(NAME_BONUS)
	@make fclean --no-print-directory -C ./libft

re: fclean all

re_bonus: fclean bonus

./libft/libft.a:
	@echo -n "Making LIBFT... "
	@make --no-print-directory -C ./libft
	@echo Done!

.PHONY: clean fclean re bonus