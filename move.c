/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:53:16 by mawad             #+#    #+#             */
/*   Updated: 2023/11/14 22:49:05 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_game(t_game *game)
{
	game->player.moves++;
	player_find(game);
	ft_draw_tiles(*game, game->player.dir);
	ft_printf("player moves: %d\n", game->player.moves);
}

int	move_up(t_game *game)
{
	int		i;
	int		j;
	int		move_result;

	j = game->player.pos_x / DIM;
	i = (game->player.pos_y / DIM) - 1;
	move_result = move_flag(game, i, j);
	if (move_result == 1)
	{
		ft_draw_tiles(*game, game->player.dir);
		game->map[i][j] = 'P';
		game->map[i + 1][j] = '0';
		update_game(game);
	}
	if (move_result == 3)
		ft_printf("Collect all coins first LOL!\n");
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
	if (move_result == 3)
		ft_printf("Collect all coins first LOL!\n");
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
	if (move_result == 3)
		ft_printf("Collect all coins first LOL!\n");
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
	if (move_result == 3)
		ft_printf("Collect all coins first LOL!\n");
	if (move_result == 2)
	{
		game->win_check = 1;
		destroy_game_post(game);
	}
	return (0);
}
