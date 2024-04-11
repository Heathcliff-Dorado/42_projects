CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = lib/libft
SRC_DIR = src/

# List of source files
MS_SRC = main.c dictionary.c expander.c lexer.c lexer_utils.c utils.c more_utils.c commands.c \
commands_utils.c cleaning.c signals.c builtin/echo.c builtin/env.c builtin/pwd.c \
builtin/builtin_utils.c builtin/cd.c builtin/export.c builtin/unset.c builtin/exit.c executor/executor_utils.c executor/executor.c \
executor/handle_pipes.c executor/other_utils.c executor/heredoc_utils.c executor/heredoc.c executor/pipe_utils.c \
executor/redirections.c \

# List of source files with prefix
MS_SRCS = $(addprefix $(SRC_DIR), $(MS_SRC))

# List of object files to build
MS_OBJS = $(MS_SRCS:.c=.o)

NAME = $(LIBFT_DIR)/libft.a

# Build both libft and minishell executables
all: $(NAME) minishell

# Build the minishell executable
minishell: $(MS_OBJS) $(NAME)
	$(CC) $(CFLAGS) -g3 $(MS_OBJS) -L$(LIBFT_DIR) -lft -lreadline -o $@

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
