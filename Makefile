NAME		=	so_long.out
CC		=	gcc
FLAGS		=	-Wall -Wextra -Werror
MLX		=	mlx/Makefile.gen
LFT		=	libft/libft.a
INC		=	-I ./get_next_line -I ./inc -I ./libft -I ./mlx
LIB		=	-L ./libft -lft -L ./mlx -lmlx -lXext -lX11 -lm -lbsd
OBJ		=	$(patsubst src%, obj%, $(SRC:.c=.o))

SRC		=	src/map_checker.c \
			src/lst_func.c \
			src/map_checker_utils.c \
			src/display_error.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			src/so_long.c

all:			$(MLX) $(LFT) obj $(NAME)

$(NAME):		$(OBJ)
			$(CC) $(FLAGS) -fsanitize=address -o $@ $^ $(LIB)

$(MLX):
			@echo " [ .. ] | Compiling minilibx.."
			@make -s -C mlx
			@echo " [ OK ] | Minilibx ready!"

$(LFT):		
			@echo " [ .. ] | Compiling libft.."
			@make -s -C libft
			@echo " [ OK ] | Libft ready!"

obj:
			@mkdir -p obj

obj/%.o:		src/%.c
			$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) obj
			@echo "object files removed."

fclean:			clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@echo "binary file removed."

re:			fclean all

.PHONY:		all clean fclean re
