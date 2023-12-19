CC = cc
CFLAGS = -Wall -Wextra -Werror

# List of source files
PHILO_SRCS = main.c monitor.c routine.c utils.c arg_check.c

# List of object files to build
PHILO_OBJS = $(PHILO_SRCS:.c=.o)

NAME = philo

# Build both the client and server executables
all: $(NAME)

# Build the client executable
$(NAME): $(PHILO_OBJS)
	$(CC) $(CFLAGS) $(PHILO_OBJS) -o $@

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files and executables
clean:
#	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(PHILO_OBJS)

# Remove object files, executables, and the libft library
fclean: clean
	$(RM) $(NAME)
#	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild the project from scratch
re: fclean all

.PHONY: all clean fclean re
