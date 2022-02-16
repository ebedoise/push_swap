SRCS		= $(addprefix ${FOLDER}/, main.c parsing.c print.c ft_atoi.c ft_split.c ft_substr.c moves.c solver.c solve5.c bigsolver.c LIS.c)
OBJS		= ${SRCS:.c=.o}
NAME		= push_swap
FOLDER		= srcs

.c.o:
			gcc -c -Wall -Wextra -Werror $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			gcc -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean
			make

.PHONY: all clean fclean re
