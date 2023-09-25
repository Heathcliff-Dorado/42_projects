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

/* Vector with x and y coordinates */
typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

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
	void	*zero;
	void	*one;
	void	*two;
	void	*three;
	void	*four;
	void	*five;
	void	*six;
	void	*seven;
	void	*eight;
	void	*nine;
	void	*black;
}				t_font;

/* Struct containing list of sprites for a given player */
typedef struct s_pl_sprite
{
	t_list	*up;
	t_list	*up_bak;
	t_list	*down;
	t_list	*down_bak;
	t_list	*left;
	t_list	*left_bak;
	t_list	*right;
	t_list	*right_bak;
	//t_list	*panic;
	//t_list	*panic_bak;
}				t_pl_sprite;

/* MLX image pointers for the map */
typedef struct s_sprite
{
	void		*logo;
	void		*wall; //Originally 2 stars, removed one
	void		*rupee;
	void		*triforce;
	void		*link;
	void		*pixels;
	void		*black;
	t_list		*pac_dying_bak;
	t_list		*pac_dying;
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
	void		*id;
	void		*w_id;
	t_layout		*layout;
	t_layout		lay_bak;
	t_sprite	sprites;
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
	int			redraw;
	int			g_rate;
}				t_game;

#endif
