NAME			=	so_long

SRCS		=	map_checker.c \
			lst_func.c \
			map_checker_utils.c \
			display_error.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			so_long.c

OBJS			=	${addprefix src/,${SRCS:.c=.o}}

LD_FLAGS		=	-L libft -L mlx

MLX_FLAGS		=	-lm -lmlx -framework OpenGL -framework AppKit

HEAD			=	-I includes -I libft -I mlx

CC			=	clang

CFLAGS			=	-Wall -Werror -Wextra -g #-fsanitize=address

.c.o			:
					${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME)			:	${OBJS}
					make -C libft
					make -C mlx
					${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} -o ${NAME} -lft ${MLX_FLAGS}

all				:	${NAME}


val				:	${NAME}
					valgrind \
					--leak-check=full --tool=memcheck \
					--show-reachable=yes \
					--track-fds=yes \
					--errors-for-leak-kinds=all \
					--show-leak-kinds=all ./${NAME}

clean			:
					make clean -C libft
					make clean -C mlx
					@rm -rf ${OBJS}

fclean			:	clean
					make fclean -C libft
					@rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re
