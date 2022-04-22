CC	=	cc
CFLAGS = -Wall -Wextra -Werror

NAME = cub3D

SRC_D	=	src
OBJ_D	=	obj
I_DIR	=	includes

RAW_C	=	main.c \
			get_next_line_utils.c \
			get_next_line.c \
			parser_load_map.c

SRC		=	$(addprefix $(SRC_D)/,$(RAW_C))
OBJ		=	$(addprefix $(OBJ_D)/,$(RAW_C:.c=.o))


.PHONY: clean fclean

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(OBJ_D)/%.o : $(SRC_D)/%.c
	$(CC) $(CFLAGS) -c $< -I $(I_DIR) -o $@

all:

clean:

fclean:

re:

bonus:
