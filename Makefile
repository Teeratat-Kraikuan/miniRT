NAME = miniRT

SRC =	main.c \
		srcs/color.c \
		srcs/vector.c

OBJ = $(SRC:.c=.o)

CFLAG = # -Wall -Wextra -Werror
CC = cc

MLX = $(MLXDIR)libmlx.a
MLXDIR = ./mlx/

LIBFT = $(LIBDIR)libft.a
LIBDIR = ./libft/

all : $(NAME)

$(NAME) : $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAG) $(OBJ) $(LIBFT) -Lmlx -lm -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJ) : %.o : %.c 
	$(CC) $(CFLAG) -Ilibft -Imlx -Iincludes -c $< -o $@

$(MLX) :
	make -C $(MLXDIR)

$(LIBFT) :
	make -C $(LIBDIR)

clean :
	make -C $(MLXDIR) clean
	make -C $(LIBDIR) clean
	rm -f $(OBJ)

fclean : clean
	make -C $(LIBDIR) fclean
	rm -f $(NAME)

re : fclean all