NAME = Account

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC = tests Account
OBJ = $(SRC:=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
