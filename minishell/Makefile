CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = lib/libft
SRC_DIR = src/

# List of source files
MS_SRC = main.c dictionary.c

# List of source files with prefix
MS_SRCS = $(addprefix $(SRC_DIR), $(MS_SRC))

# List of object files to build
MS_OBJS = $(MS_SRCS:.c=.o)

NAME = $(LIBFT_DIR)/libft.a

# Build both push_swap and checker executables
all: $(NAME) minishell

# Build the push_swap executable
minishell: $(MS_OBJS) $(NAME)
	$(CC) $(CFLAGS) -g3 -lreadline $(MS_OBJS) -L$(LIBFT_DIR) -lft -o $@

# Build the libft library
$(NAME): $(LIBFT_DIR)/*.c
	$(MAKE) -C $(LIBFT_DIR) all

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files and executables
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(MS_OBJS)

# Remove object files, executables, and the libft library
fclean: clean
	$(RM) minishell
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild the project from scratch
re: fclean all

.PHONY: all clean fclean re
