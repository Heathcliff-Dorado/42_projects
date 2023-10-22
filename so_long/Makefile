CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = lib/libft
LIBMLX	:= ./lib/MLX42
SRC_DIR = src/

# List of source files
SO_LONG_SRC = main.c map_parsing.c load_score.c load_sprites.c load_animation.c movement.c utils.c

# List of source files with prefix
SO_LONG_SRCS = $(addprefix $(SRC_DIR), $(SO_LONG_SRC))

# List of object files to build
SO_LONG_OBJS = $(SO_LONG_SRCS:.c=.o)

NAME = $(LIBFT_DIR)/libft.a

# Build both push_swap and checker executables
all: $(NAME) so_long

####LINUX##### add "libmlx" to rule in all
## Build the MLX42 library
#libmlx:
#	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

## Build the so_long executable
#so_long: $(SO_LONG_OBJS) $(NAME)
#	$(CC) $(CFLAGS) $(SO_LONG_OBJS) -L$(LIBFT_DIR) -lft $(LIBMLX)/build/libmlx42.a -ldl -lglfw(3) -pthread -lm -o $@

####MacOS#####
# Build the so_long executable
so_long: $(SO_LONG_OBJS) $(NAME)
	$(CC) $(CFLAGS) $(SO_LONG_OBJS) -L$(LIBFT_DIR) -lft ../MLX42/build/libmlx42.a -lglfw -L"/Users/hdorado/homebrew/Cellar/glfw/3.3.8/lib/" -framework Cocoa -framework OpenGL -framework IOKit -o $@

# Build the libft library
$(NAME): $(LIBFT_DIR)/*.c
	$(MAKE) -C $(LIBFT_DIR) all

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files and executables
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(SO_LONG_OBJS)

# Remove object files, executables, and the libft library
fclean: clean
	$(RM) so_long
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild the project from scratch
re: fclean all

.PHONY: all clean fclean re
