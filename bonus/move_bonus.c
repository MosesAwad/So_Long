/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:53:16 by mawad             #+#    #+#             */
/*   Updated: 2023/11/15 20:25:05 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_game(t_game *game)
{
	char	*moves;

	game->player.moves++;
	player_find(game);
	ft_draw_tiles(*game, game->player.dir);
	moves = ft_itoa(game->player.moves);
	mlx_put_image_to_window(game->mlx, game->win.mlx_win,
		game->album[0].img, (game->win.x / 2) * DIM + DIM, 0);
	mlx_string_put(game->mlx, game->win.mlx_win,
		(game->win.x / 2) * DIM, DIM / 2, 0x00FF66, "Moves:");
	mlx_string_put(game->mlx, game->win.mlx_win,
		(game->win.x / 2) * DIM + DIM, DIM / 2, 0x00FF66, moves);
	free(moves);
}

int	move_up(t_game *game)
{
	int		i;
	int		j;
	int		move_result;

	j = game->player.pos_x / DIM;
	i = (game->player.pos_y / DIM) - 1;
	move_result = move_flag(game, i, j);
	game->player.dir = 3;
	if (move_result == 1)
	{
		ft_draw_tiles(*game, game->player.dir);
		game->map[i][j] = 'P';
		game->map[i + 1][j] = '0';
		update_game(game);
	}
	if (move_result == 0)
		move_wall(game, i + 1, j, game->player.dir);
	if (move_result == 4)
		return (1);
	if (move_result == 2)
	{
		game->win_check = 1;
		destroy_game_post(game);
	}
	return (0);
}

int	move_down(t_game *game)
{
	int		i;
	int		j;
	int		move_result;

	j = game->player.pos_x / DIM;
	i = game->player.pos_y / DIM + 1;
	move_result = move_flag(game, i, j);
	if (move_result == 1)
	{
		ft_draw_tiles(*game, game->player.dir);
		game->map[i][j] = 'P';
		game->map[i - 1][j] = '0';
		update_game(game);
	}
	if (move_result == 0)
		move_wall(game, i - 1, j, game->player.dir);
	if (move_result == 4)
		return (1);
	if (move_result == 2)
	{
		game->win_check = 1;
		destroy_game_post(game);
	}
	return (0);
}

int	move_left(t_game *game)
{
	int		i;
	int		j;
	int		move_result;

	j = game->player.pos_x / DIM - 1;
	i = game->player.pos_y / DIM;
	game->player.dir = 1;
	move_result = move_flag(game, i, j);
	if (move_result == 1)
	{
		ft_draw_tiles(*game, game->player.dir);
		game->map[i][j] = 'P';
		game->map[i][j + 1] = '0';
		update_game(game);
	}
	if (move_result == 0)
		move_wall(game, i, j + 1, game->player.dir);
	if (move_result == 4)
		return (1);
	if (move_result == 2)
	{
		game->win_check = 1;
		destroy_game_post(game);
	}
	return (0);
}

int	move_right(t_game *game)
{
	int		i;
	int		j;
	int		move_result;

	j = game->player.pos_x / DIM + 1;
	i = game->player.pos_y / DIM;
	game->player.dir = 0;
	move_result = move_flag(game, i, j);
	if (move_result == 1)
	{
		ft_draw_tiles(*game, game->player.dir);
		game->map[i][j] = 'P';
		game->map[i][j - 1] = '0';
		update_game(game);
	}
	if (move_result == 0)
		move_wall(game, i, j - 1, game->player.dir);
	if (move_result == 4)
		return (1);
	if (move_result == 2)
	{
		game->win_check = 1;
		destroy_game_post(game);
	}
	return (0);
}
