SRC			= main.c checklineforrules.c clean_parameter.c common_functions.c get_value.c list_sort.c open_dict.c parse_dictionary.c print_nbr.c returnliteral.c write_dict.c

SRCS		= ${SRC}

OBJS		= ${SRCS:.c=.o}

HEAD		= ./

DICT		= ./

NAME		= rush-02

RM			= rm -f

GCC			= gcc

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
			${GCC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${GCC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
			echo $test
			rm -f ${OBJS}
			echo $posttest

fclean:	clean
			echo $test
			rm -f ${NAME}
			echo $posttest
re:			fclean all

.PHONY:	clean

