/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:34:59 by hdorado-          #+#    #+#             */
/*   Updated: 2023/11/03 21:03:01 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# include "../lib/libft/libft.h"
# include "MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_lists
{
	mlx_image_t			*content;
	struct s_lists		*next;
}				t_lists;

typedef struct s_layout
{
	int	row;
	int	col;
	int	exit;
	int	player;
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
}				t_pl_sprite;

/* MLX image pointers for the map */
typedef struct s_sprite
{
	mlx_image_t		*wall;
	mlx_image_t		*rupee;
	mlx_image_t		*triforce;
	mlx_image_t		*triforceon;
	mlx_image_t		*black;
	mlx_image_t		*cover;
	t_font			fnt;
}				t_sprite;

/* Main Player struct with position and direction (linked list) */
typedef struct s_player
{
	t_vector		pos;
	t_vector		win_pos;
	int				dir;
	int				moving;
	t_pl_sprite		sp;
}				t_player;

/*n_frames in case computer is too fast, not in 42 though*/
typedef struct s_game
{
	int			w;
	int			h;
	mlx_t		*id;
	mlx_image_t	*w_id;
	t_layout	*layout;
	t_layout	lay_bak;
	t_sprite	sp;
	int			pla;
	t_player	*pl;
	char		**map;
	char		**map_bak;
	int			col_bak;
	int			n_frames;
	int			n_moves;
	int			n_moves_bak;
}				t_game;

//Functions in main
void		ft_update_moves(t_game *g);
void		ft_update_game(void *param);
void		ft_setgame(t_game *g, char **m, t_layout *lay);
void		ft_initgame(char **map, t_layout lay);
//Functions in map_parsing
int			ft_um_new(char ***map, char **new_map, char *str, int i);
int			ft_update_map(char ***map, t_layout *layout, char *str);
int			ft_check_map(int fd, t_layout *layout, char ***map);
int			ft_open_map(char *directory, t_layout *layout, char ***map);
int			parse_map(int argc, char **argv, t_layout *layout, char ***map);
//Functions in map_checks
int			ft_check_surroundings(char **map, int i, int j, t_layout *layout);
int			ft_valid_path(char ***map, t_layout *layout);
int			is_map_right(char ***map, t_layout *layout);
int			parse_icons(char ***map, t_layout *layout);
int			icons_check(char ***map, t_layout *layout, int i, int j);
//Functions in map_filling
void		ft_fillbackground(t_game *g);
void		ft_fillothers(t_game *g);
void		ft_fillplayer(t_game *g);
int			ft_draw(t_game *g);
//Functions in map_utils
void		ft_freemap(char ***map);
int			ft_dupmap(char **src, char ***dst);
void		ft_newlayout(t_layout *layout);
int			ft_map_length(char ***map);
//Functions in load_sprites
int			ft_initsprites2(t_game *g);
int			ft_initsprites(t_game *g);
int			ft_load_links(t_game *g);
void		ft_render_link(t_lists *sprite, int x, int y, mlx_t *id);
//Functions in load_animations
int			ft_load_north(t_game *g, char *path, int i);
int			ft_load_south(t_game *g, char *path, int i);
int			ft_load_east(t_game *g, char *path, int i);
int			ft_load_west(t_game *g, char *path, int i);
//Functions in load_score
void		ft_load_all_sc(t_game *g, int i);
void		ft_render_scoreboard(t_game *g);
int			ft_load3(t_game *g);
int			ft_load2(t_game *g);
int			ft_load_font(t_game *g);
//Functions in change_score
void		ft_disable_all(t_font font);
void		ft_enable(t_game *g, int i);
void		ft_change_score(t_game *g, int digit, int i);
//Functions in movement
void		ft_moving_north(t_game *g);
void		ft_moving_south(t_game *g);
void		ft_moving_west(t_game *g);
void		ft_moving_east(t_game *g);
void		ft_moving(t_game *g);
//Functions in direction
void		ft_changedir2(t_game *g, int dir);
void		ft_changedir(t_game *g, int dir);
int			ft_moveallowed(t_game *g);
void		choose_action(t_game *g, int dir);
void		my_keyhook(mlx_key_data_t keydata, void *param);
//Functions in utils
void		ft_lstadd_back_s(t_lists **lst, t_lists *new);
t_lists		*ft_lstnew_s(mlx_image_t *content);
t_vector	ft_newvector(int x, int y);
void		ft_plradd_back(t_player **lst, t_player *newnode);
//Functions in cleaning
void		ft_freestructure(char **map);
void		ft_animclean(t_lists *list);
void		ft_freegame(t_game *g);
void		ft_error_handling(int errno);
t_player	*ft_plrnew(t_vector pos);

#endif
