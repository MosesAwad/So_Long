/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rules_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:03:39 by mawad             #+#    #+#             */
/*   Updated: 2023/11/15 20:47:35 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	map_rules1(t_game game)
{
	int		i;

	i = 0;
	while (game.map[i])
	{
		if ((i > 0) && ft_strlen(game.map[i]) != ft_strlen(game.map[i - 1]))
			return (0);
		i++;
	}
	if (i == 1 || i == 0)
		return (0);
	return (1);
}

int	map_rules2(t_game game)
{
	int		i;
	int		j;
	char	*set;

	set = "10CPEN";
	i = 0;
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
		{
			if (!ft_strchr(set, game.map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	wall_rules1(t_game game)
{
	int	i;
	int	j;

	i = 0;
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
			j++;
		if (game.map[i][0] != '1' || game.map[i][j - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	wall_rules2(t_game game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game.map[0][j] == '1')
		j++;
	if (game.map[0][j] != '\0')
		return (0);
	while (game.map[i])
	{
		if (game.map[i][0] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (game.map[i - 1][j] == '1')
		j++;
	if (game.map[i - 1][j] != '\0')
		return (0);
	return (1);
}
