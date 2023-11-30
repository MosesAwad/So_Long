/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:34:31 by mawad             #+#    #+#             */
/*   Updated: 2023/11/15 21:12:19 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_hook(int keycode, t_game *game)
{
	int		res;

	res = 0;
	if (keycode == W_KEY)
		res = move_up(game);
	else if (keycode == A_KEY)
		res = move_left(game);
	else if (keycode == S_KEY)
		res = move_down(game);
	else if (keycode == D_KEY)
		res = move_right(game);
	else if (keycode == ESC_KEY)
		destroy_game_post(game);
	if (res == 1)
	{
		ft_printf("You touched an enemy!\n");
		destroy_game_post(game);
	}
	return (0);
}

void	initializer(t_game *game)
{
	int	x;
	int	y;

	x = ft_line_length(game->map[0]);
	y = ft_line_count(game->map);
	game->player_check = 0;
	game->exit_check = 0;
	game->coin_check = 0;
	game->player.coincheck = 0;
	game->dfs_coincount = 0;
	game->player.moves = 0;
	game->player.dir = 0;
	game->enemy_dir = 0;
	game->enemy_check = 0;
	game->win_check = 0;
	game->win.x = x;
	game->win.y = y;
	game->speed = 0;
	game->coin_flash = 0;
	game->win.mlx_win = mlx_new_window(game->mlx,
			game->win.x * DIM, game->win.y * DIM, "ARENA");
	player_find(game);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	if (argc != 2)
		return (ft_printf("Please insert strictly 2 arguments!\n"), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error:\nCheck file/folder name)\n"), 1);
	if (!file_parser(argv[1]))
		return (close(fd), 1);
	game.map = get_map(fd);
	game.mlx = mlx_init();
	if (!game.map || !game.mlx)
		return (1);
	initializer(&game);
	game_stats(&game);
	mlx_hook(game.win.mlx_win, 17, 0L, destroy_game_post, &game);
	ft_draw_map(game);
	ft_draw_tiles(game, game.player.dir);
	mlx_key_hook(game.win.mlx_win, key_hook, &game);
	mlx_loop_hook(game.mlx, move_animation, &game);
	mlx_loop(game.mlx);
	return (0);
}
