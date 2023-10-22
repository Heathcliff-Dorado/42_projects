#ifndef SO_LONG_H
# define SO_LONG_H
# define SIZE 32
# define HEIGHT 512
# define WIDTH 512
# define DEFAULT "\033[0;39m"
# define GRAY "\033[0;90m"
# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define BLUE "\033[0;94m"
# define MAGENTA "\033[0;95m"
# define CYAN "\033[0;96m"
# define WHITE "\033[0;97m"
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_R 15
# define KEY_Q 12
# define COLORS "RBKOGYP"
# define GAME_RATE 17

# include "../lib/libft/libft.h"
# include "../../MLX42/include/MLX42/MLX42_Int.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

//Structures

/* Vector with x and y coordinates */
typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_lists
{
	mlx_image_t			*content;
	struct s_lists	*next;
}				t_lists;

typedef struct s_layout
{
	int	row;
	int	col;
	int	exit;
	int	player;
	int	enemy;
	int	collect;
}				t_layout;

enum e_direction
{
	ST = 0,
	N = 1,
	S = -1,
	E = 2,
	W = -2
};

/* Struct to store the sprites for every digit */
typedef struct s_font
{
	mlx_image_t	*zero;
	mlx_image_t	*one;
	mlx_image_t	*two;
	mlx_image_t	*three;
	mlx_image_t	*four;
	mlx_image_t	*five;
	mlx_image_t	*six;
	mlx_image_t	*seven;
	mlx_image_t	*eight;
	mlx_image_t	*nine;
	mlx_image_t	*black;
}				t_font;

/* Struct containing list of sprites for a given player */
typedef struct s_pl_sprite
{
	t_lists	*up;
	t_lists	*up_bak;
	t_lists	*down;
	t_lists	*down_bak;
	t_lists	*left;
	t_lists	*left_bak;
	t_lists	*right;
	t_lists	*right_bak;
	//t_list	*panic;
	//t_list	*panic_bak;
}				t_pl_sprite;

/* MLX image pointers for the map */
typedef struct s_sprite
{
	mlx_image_t		*logo;
	mlx_image_t		*wall; //Originally 2 stars, removed one
	mlx_image_t		*rupee;
	mlx_image_t		*triforce;
	mlx_image_t		*cover;
	mlx_image_t		*triforceon;
	mlx_image_t		*black;
	t_lists		*pac_dying_bak;
	t_lists		*pac_dying;
	t_font		score_font;
}				t_sprite;

/* Small list showing if a player can go north, south, east or west */
typedef struct s_legal_actions
{
	int	north;
	int	south;
	int	east;
	int	west;
}				t_legal_actions;

/* Main Player struct with position and direction (linked list) */
typedef struct s_player
{
	t_vector		pos;
	t_vector		win_pos;
	int				dir;
	int				moving;
	t_pl_sprite		sprites;
	t_legal_actions	legal;
	struct s_player	*next;
}				t_player;

typedef struct s_game
{
	int			width;
	int			height;
	mlx_t		*id;
	mlx_image_t		*w_id;
	t_layout		*layout;
	t_layout		lay_bak;
	t_sprite	sprites;
	int			pla;
	t_player	*pl;
	//t_player	*gh;
	int			next_dir;
	char		**map;
	char		**map_bak;
	int			n_collect_bak;
	int			pac_dying;
	//int			panic_mode;
	int			n_frames;
	int			n_moves;
	int			n_moves_bak;
	int			g_rate;
}				t_game;

//Functions in main

//Functions in map_parsing
int ft_check_surroundings(char **map, int i, int j, t_layout *layout);
void	ft_freemap(char ***map);
int	ft_dupmap(char **src, char ***dst);
int ft_valid_path(char ***map, t_layout *layout);
int	parse_icons(char ***map, t_layout *layout);
int	is_map_right(char ***map, t_layout *layout);
int	ft_update_map(char ***map, t_layout *layout, char *str);
int	ft_check_map(int fd, t_layout *layout, char ***map);
int	ft_open_map(char *directory, t_layout *layout, char ***map);
int	parse_map(int argc, char **argv, t_layout *layout, char ***map);
void	ft_newlayout(t_layout *layout);
//Functions in load_sprites
t_sprite	ft_initsprites(t_game *g);
void	ft_load_links(t_game *g);
void	ft_render_link(t_lists *sprite, int x, int y, mlx_t *id);
//Functions in load_animations
t_lists	*ft_load_north(t_game *g, char *path, int i);
t_lists	*ft_load_south(t_game *g, char *path, int i);
t_lists	*ft_load_east(t_game *g, char *path, int i);
t_lists	*ft_load_west(t_game *g, char *path, int i);
//Functions in load_score
void	ft_disable_all(t_font font);
void	ft_enable(t_game *g, int i);
void	ft_change_score(t_game *g, int digit, int i);
void	ft_render_scoreboard(t_game *g);
t_font	ft_load_font(t_game *g);
//Functions in movement
void	ft_moving_north(t_game *g);
void	ft_moving_south(t_game *g);
void	ft_moving_west(t_game *g);
void	ft_moving_east(t_game *g);
void	ft_moving(t_game *g);
//Functions in utils
void	ft_lstadd_back_s(t_lists **lst, t_lists *new);
t_lists	*ft_lstnew_s(mlx_image_t *content);
t_vector	ft_newvector(int x, int y);
void	ft_plradd_back(t_player **lst, t_player *newnode);

#endif
