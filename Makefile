CC	=	cc
CFLAGS = -Wall -Wextra -Werror

NAME 		= cub3D

SRC_D		=	src
OBJ_D		=	obj
INCLUDES	=	-I ./includes

LIBS		=	-L./libft -lft

RAW_C		=	main.c \
				get_next_line.c \
				parser_load_map.c

SRC			=	$(addprefix $(SRC_D)/,$(RAW_C))
OBJ			=	$(addprefix $(OBJ_D)/,$(RAW_C:.c=.o))


.PHONY: clean fclean

$(NAME): $(OBJ) 
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

$(OBJ_D)/%.o : $(SRC_D)/%.c ./libft/libft.a
	$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

all:	$(NAME)

clean:
	$(RM) $(OBJ)
	@make clean -C ./libft

fclean:	clean
	$(RM) $(NAME)
	@make fclean -C ./libft

re: fclean all

./libft/libft.a:
	@make -C ./libft

bonus:
