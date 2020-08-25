SRCS	=		get_next_line.c			\
				get_next_line_utils.c	\
				parsing.c				\
				main.c					\

OBJS	=	${SRCS:.c=.o}

CC		=	gcc
RM		=	rm -f
NAME	=	bsq

FLAGS	=	-g -O3 -o bsq

all:		${SRCS}
			${CC} ${FLAGS} ${SRCS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
