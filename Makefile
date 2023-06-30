NAME = miniRT

SRC =	srcs/main.c		\
		srcs/struct/camera.c		\
		srcs/struct/color.c			\
		srcs/struct/init.c			\
		srcs/rendering/render.c		\
		srcs/handler/event.c		\
		srcs/vector/vector.c		\
		srcs/utils/utils.c			\
		srcs/utils/put_pixel.c		\
		srcs/lexer/error_message.c	\
		srcs/lexer/check_file.c		\
		srcs/lexer/check_infile.c	\
		srcs/lexer/check_object.c	\
		srcs/lexer/get_infile.c		\
		srcs/lexer/get_variable.c	\
		srcs/lexer/get_object.c		\
		srcs/lexer/good_number.c		\
		srcs/lexer/good_variable.c	\
		srcs/lexer/get_next_line.c	\
		srcs/lexer/get_next_line_utils.c	\
		srcs/lexer/ft_split_white.c	\
		srcs/lexer/ft_atof.c			\
		srcs/lexer/lexer_until.c		\
		srcs/lexer/objs_manager.c	\
		srcs/lexer/free.c

OBJ = $(SRC:.c=.o)

CFLAG = # -g -fsanitize=address # -Wall -Wextra -Werror
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