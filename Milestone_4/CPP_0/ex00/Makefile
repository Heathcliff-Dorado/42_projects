NAME = megaphone

CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CPP = g++

SRC = megaphone.cpp

all: $(NAME)

#%.o: %.c
#	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME):
	@$(CPP) $(CPPFLAGS) $(SRC) -o $(NAME)

#clean:
#	@rm -rf $(OBJS)

fclean:
	@rm -rf $(NAME)

re: fclean all

.PHONY: all fclean re
