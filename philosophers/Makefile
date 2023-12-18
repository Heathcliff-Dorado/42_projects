CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = lib/libft
SRC_DIR = src/

# List of source files
PHILO_SRC = main.c monitor.c routine.c utils.c arg_check.c
PHILO_SRCS = $(addprefix $(SRC_DIR), $(PHILO_SRC))

# List of object files to build
PHILO_OBJS = $(PHILO_SRCS:.c=.o)

NAME = $(LIBFT_DIR)/libft.a

# Build both the client and server executables
all: $(NAME) philosophers

# Build the client executable
philosophers: $(PHILO_OBJS) $(NAME)
	$(CC) -fsanitize=address $(CFLAGS) $(PHILO_OBJS) -L$(LIBFT_DIR) -lft -o $@

# Build the libft library
$(NAME): $(LIBFT_DIR)/*.c
	$(MAKE) -C $(LIBFT_DIR) all

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files and executables
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(PHILO_OBJS)

# Remove object files, executables, and the libft library
fclean: clean
	$(RM) client server
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild the project from scratch
re: fclean all

.PHONY: all clean fclean re
