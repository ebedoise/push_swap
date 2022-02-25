SRCS		= $(addprefix ${FOLDER}/, push_swap.c parsing.c print.c ft_atoi.c ft_split.c ft_substr.c moves.c solver.c solve5.c bigsolver.c bigsolver_bis.c LIS.c)
SRCS_BONUS		= $(addprefix ${FOLDER_BONUS}/, checker.c parsing.c print.c ft_atoi.c ft_split.c ft_substr.c moves.c check_stdin.c ft_strjoin.c)
OBJS		= ${SRCS:.c=.o}
OBJS_BONUS		= ${SRCS_BONUS:.c=.o}
NAME		= push_swap
NAME_BONUS	= checker
FOLDER		= srcs
FOLDER_BONUS	= srcs_bonus

.c.o:
			gcc -c -Wall -Wextra -Werror $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			gcc -o ${NAME} ${OBJS}

${NAME_BONUS}:	${OBJS_BONUS}
				gcc -o ${NAME_BONUS} ${OBJS_BONUS}

all:		${NAME}

bonus:		${NAME_BONUS}

clean:
			rm -f ${OBJS}
			rm -f ${OBJS_BONUS}

fclean:		clean
			rm -f ${NAME}
			rm -f ${NAME_BONUS}

re:			fclean
			make

.PHONY: all clean fclean re bonus
