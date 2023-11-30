/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:15:33 by mawad             #+#    #+#             */
/*   Updated: 2023/11/14 22:48:54 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_stats(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				game->player_check++;
			if (game->map[i][j] == 'C')
				game->coin_check++;
			if (game->map[i][j] == 'E')
				game->exit_check++;
			j++;
		}
		i++;
	}
	message(game);
	load_images(game);
	imgmsg_loadcheck(game);
}

void	player_find(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
			{
				game->player.pos_x = j * DIM;
				game->player.pos_y = i * DIM;
			}
			j++;
		}
		i++;
	}
}

int	move_flag(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'C')
	{
		game->player.coincheck++;
		game->map[i][j] = '0';
		return (1);
	}
	if (game->map[i][j] == '1')
		return (0);
	if (game->map[i][j] == 'E' && (game->player.coincheck != game->coin_check))
		return (3);
	if (game->map[i][j] == 'E' && (game->player.coincheck == game->coin_check))
		return (2);
	return (1);
}

int	file_parser(char *str)
{
	int			i;
	int			j;
	int			count;
	const char	*set;

	i = 0;
	count = 0;
	j = 4;
	set = ".ber";
	while (str[i])
		i++;
	while (j >= 0)
	{
		if (str[i--] != set[j--])
		{
			ft_printf("Error\nWrong file extension!");
			return (0);
		}
	}
	return (1);
}
