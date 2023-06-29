CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = include/libft

# List of source files
CLIENT_SRCS = push_swap.c

# List of object files to build
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

NAME = $(LIBFT_DIR)/libft.a

# Build both the client and server executables
all: $(NAME) client 

# Build the client executable
client: $(CLIENT_OBJS) $(NAME)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -L$(LIBFT_DIR) -lft -o $@

# Build the libft library
$(NAME): $(LIBFT_DIR)/*.c
	$(MAKE) -C $(LIBFT_DIR) all

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files and executables
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(CLIENT_OBJS)

# Remove object files, executables, and the libft library
fclean: clean
	$(RM) client
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild the project from scratch
re: fclean all

.PHONY: all clean fclean re
