NAME			=	so_long

SRCS			=	get_next_line.c ft_parse.c ft_split.c parse_utils.c path_finding.c get_next_line_utils.c make_x.c so_long.c graphics.c move.c parse_utils_2.c ft_printf.c ft_printf_utils.c free.c

OBJS			=	${SRCS:.c=.o}

MLX_FLAGS		=	-lm -lmlx -lXext -lX11

CC				=	cc

CFLAGS			=	-Wall -Werror -Wextra -g3

all				:	${NAME}

$(NAME): $(OBJS)
	cc $(OBJS) mlx/libmlx.a mlx/libmlx_Linux.a -L. -lXext -L. -lX11 -o $(NAME)

clean			:
					rm -rf ${OBJS}

fclean			:	clean
					rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re
