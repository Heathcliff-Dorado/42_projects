NAME = libftprintf.a

CC = cc

CCFLAG = -Wall -Wextra -Werror

AR = ar

ARFLAG = crs

SRCS_1 = ft_printf.c ft_printf_helpers.c

SRCS = $(SRCS_1)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
		$(AR) $(ARFLAG) $@ $^

%.o: %.c
		$(CC) $(CCFLAG) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
