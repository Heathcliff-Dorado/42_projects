CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = lib/libft
SRC_DIR = src/

# List of source files
PS_SRC = push_swap.c push_swap_utils.c push_swap_utils_2.c push_swap_utils_3.c push_swap_utils_4.c push_swap_utils_5.c
CHECKER_SRC = checker.c checker_utils.c
COMMON_SRC = common_functions.c common_functions_2.c

# List of source files with prefix
PS_SRCS = $(addprefix $(SRC_DIR), $(PS_SRC))
CHECKER_SRCS = $(addprefix $(SRC_DIR), $(CHECKER_SRC))
COMMON_SRCS = $(addprefix $(SRC_DIR), $(COMMON_SRC))

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
	$(RM) push_swap checker
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild the project from scratch
re: fclean all

.PHONY: all clean fclean re
