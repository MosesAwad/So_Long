/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:47:03 by mawad             #+#    #+#             */
/*   Updated: 2023/11/14 22:49:41 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define DIM 48
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define ESC_KEY 53

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_player {
	int	pos_x;
	int	pos_y;
	int	coincheck;
	int	moves;
	int	dir;
}		t_player;

typedef struct s_image {
	void	*img;
	int		img_width;
	int		img_height;
}			t_image;

typedef struct s_window {
	int		x;
	int		y;
	void	*mlx_win;
}			t_window;

typedef struct s_game {
	void		*mlx;
	t_window	win;
	t_image		album[6];
	t_player	player;
	int			player_check;
	int			dfs_coincount;
	int			coin_check;
	int			exit_check;
	int			win_check;
	char		**map;
}			t_game;

typedef struct s_index {
	int	i;
	int	j;
}			t_index;

int		destroy_game_post(t_game *game);
int		destroy_game_pre(t_game *game);
void	destroy_map(char **map );
void	destroy_images(t_game *game);

char	**mark_map(char **map);
void	find_neighbors(int i, int j, t_index *neighbors);
void	dfs(t_game *game, char **mark_map, int j, int i);
int		valid_path_check(t_game game, char **mark_map);

int		map_rules1(t_game game);
int		map_rules2(t_game game);
int		wall_rules1(t_game game);
int		wall_rules2(t_game game);

int		game_checker(t_game game);
void	imgmsg_loadcheck(t_game *game);
void	message(t_game *game);

void	update_game(t_game *game);
int		move_up(t_game *game);
int		move_down(t_game *game);
int		move_right(t_game *game);
int		move_left(t_game *game);

void	game_stats(t_game *game);
void	player_find(t_game *game);
int		move_flag(t_game *game, int i, int j);
int		file_parser(char *str);

int		image_parser(t_game game);
void	load_images(t_game *game);
void	put_image(t_game game, int i, int j, int flag);

void	print_map(char **map);
void	ft_draw_map(t_game game);
void	ft_draw_tiles(t_game game, int flag);

int		ft_line_count(char **map);
char	*get_next_line(int fd);
int		ft_line_length(char *map_row);

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	**get_map(int fd);

#endif
