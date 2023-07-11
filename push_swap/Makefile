CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = include/libft

# List of source files
PS_SRCS = push_swap.c
CHECKER_SRCS = checker.c checker_utils.c
COMMON_SRCS = common_functions.c

# List of object files to build
PS_OBJS = $(PS_SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)
COMMON_OBJS = $(COMMON_SRCS:.c=.o)

NAME = $(LIBFT_DIR)/libft.a

# Build both push_swap and checker executables
all: $(NAME) push_swap checker

# Build the push_swap executable
push_swap: $(PS_OBJS) $(COMMON_OBJS) $(NAME)
	$(CC) $(CFLAGS) $(PS_OBJS) $(COMMON_OBJS) -L$(LIBFT_DIR) -lft -o $@

# Builds the checker
checker: $(CHECKER_OBJS) $(COMMON_OBJS) $(NAME) 
	$(CC) $(CFLAGS) $(CHECKER_OBJS) $(COMMON_OBJS) -L$(LIBFT_DIR) -lft -o $@

# Build the libft library
$(NAME): $(LIBFT_DIR)/*.c
	$(MAKE) -C $(LIBFT_DIR) all

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files and executables
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(PS_OBJS) $(COMMON_OBJS) $(CHECKER_OBJS)

# Remove object files, executables, and the libft library
fclean: clean
	$(RM) push_swap checker common
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild the project from scratch
re: fclean all

.PHONY: all clean fclean re
