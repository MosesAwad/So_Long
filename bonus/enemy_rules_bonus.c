/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_rules_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:40:51 by mawad             #+#    #+#             */
/*   Updated: 2023/11/15 20:25:52 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	find_enemy(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N')
			{
				enemy_pos(game, i, j);
				game->enemy_check++;
			}
			j++;
		}
		i++;
	}
}

void	enemy_pos(t_game *game, int i, int j)
{
	int	k;

	k = 0;
	while (k < 4)
	{
		if (game->map[i][j - k] == '1' || game->map[i][j - k] == 'C')
		{
			ft_printf("Enemy within 3 spaces of wall or coin\n");
			destroy_game_pre(game);
		}
		k++;
	}
}
