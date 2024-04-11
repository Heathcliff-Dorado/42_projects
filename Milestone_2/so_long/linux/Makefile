CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = lib/libft
MLX42	:= ./lib/MLX42
SRC_DIR = src/

# List of source files
SO_LONG_SRC = change_score.c cleaning.c direction.c load_animation.c load_score.c load_sprites.c main.c map_checks.c \
	map_filling.c map_parsing.c map_utils.c movement.c utils.c \

# List of source files with prefix
SO_LONG_SRCS = $(addprefix $(SRC_DIR), $(SO_LONG_SRC))

# List of object files to build
SO_LONG_OBJS = $(SO_LONG_SRCS:.c=.o)

NAME = $(LIBFT_DIR)/libft.a

# Build both push_swap and checker executables
all: $(NAME) getmlx42 so_long

####LINUX##### add "libmlx" to rule in all
# Build the so_long executable
so_long: $(SO_LONG_OBJS) $(NAME)
	$(CC) $(CFLAGS) $(SO_LONG_OBJS) -L$(LIBFT_DIR) -lft $(MLX42)/build/libmlx42.a -ldl -lglfw -pthread -lm -o $@

#Get MLX42
getmlx42:
	@if [ ! -d $(MLX42) ]; then \
		echo "Downloading miniLibX..."; \
		git clone https://github.com/codam-coding-college/MLX42.git $(MLX42); \
		cd $(MLX42); cmake -B build; cmake --build build -j4; cd ../..;\
		cp $(MLX42)/include/MLX42/MLX42.h ./inc; \
		cp $(MLX42)/build/libmlx42.a ./inc; \
	fi

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
