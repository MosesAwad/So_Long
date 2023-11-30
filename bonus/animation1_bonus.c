/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:05:08 by mawad             #+#    #+#             */
/*   Updated: 2023/11/15 19:22:23 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_back(t_game *game, int i, int j)
{
	static int	steps_back;
	int			limit;

	limit = game->enemy_check * 3;
	if (steps_back == limit)
	{
		steps_back = 0;
		game->enemy_dir = 0;
	}
	if (steps_back < limit && game->enemy_dir == 1)
	{
		game->map[i][j] = '0';
		game->map[i][j + 1] = 'N';
		ft_draw_tiles(*game, game->player.dir);
		steps_back++;
	}
}

void	move_enemy(t_game *game, int i, int j)
{
	static int	steps;
	int			limit;

	limit = game->enemy_check * 3;
	if (steps == limit)
	{
		steps = 0;
		game->enemy_dir = 1;
	}
	if (steps < limit && game->enemy_dir == 0)
	{
		game->map[i][j] = '0';
		game->map[i][j - 1] = 'N';
		ft_draw_tiles(*game, game->player.dir);
		steps++;
	}
}

void	anim_find1(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N')
				move_enemy(game, i, j);
			j++;
		}
		i++;
	}
}

void	anim_find2(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
			j++;
		while (j >= 0)
		{
			if (game->map[i][j] == 'N')
				move_back(game, i, j);
			j--;
		}
		i++;
	}
}

int	move_animation(t_game *game)
{
	game->speed++;
	if (game->speed >= 1450)
	{
		if (game->enemy_dir == 0)
			anim_find1(game);
		if (game->enemy_dir == 1)
			anim_find2(game);
		if (game->coin_flash != 2)
			coin_anim1(game);
		if (game->coin_flash == 2)
			coin_anim2(game);
		game->speed = 0;
	}
	if (player_eat(game) == 0)
	{
		ft_printf("You touched an enemy!\n");
		destroy_game_post(game);
	}
	return (0);
}
