/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:42:31 by mawad             #+#    #+#             */
/*   Updated: 2023/11/14 22:49:11 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**mark_map(char **map)
{
	char	**mark_map;
	int		rows;
	int		cols;
	int		i;
	int		j;

	rows = ft_line_count(map);
	cols = ft_line_length(map[0]);
	mark_map = (char **)malloc(sizeof(char *) * (rows + 1));
	i = 0;
	while (map[i])
		mark_map[i++] = malloc(sizeof(char) * (cols + 1));
	mark_map[i] = NULL;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			mark_map[i][j++] = 'F';
		mark_map[i][j] = '\0';
		i++;
	}
	return (mark_map);
}

void	find_neighbors(int j, int i, t_index *neighbors)
{
	neighbors[0] = (t_index){i - 1, j};
	neighbors[1] = (t_index){i + 1, j};
	neighbors[2] = (t_index){i, j - 1};
	neighbors[3] = (t_index){i, j + 1};
}

void	dfs(t_game *game, char **mark_map, int j, int i)
{
	t_index			neighbors[4];
	int				k;

	mark_map[i][j] = 'T';
	if (game->map[i][j] == 'C')
		game->dfs_coincount++;
	k = 0;
	find_neighbors(j, i, neighbors);
	while (k < 4)
	{
		i = neighbors[k].i;
		j = neighbors[k].j;
		if (!(game->map[i][j] == '1' || game->map[i][j] == 'E')
			&& mark_map[i][j] == 'F')
		{
			dfs(game, mark_map, j, i);
		}
		k++;
	}
}

int	check_exit(t_game game, char **mark_map, int j, int i)
{
	t_index	neighbors[4];
	int		k;
	int		untraversables;

	if (game.dfs_coincount != game.coin_check)
		return (0);
	find_neighbors(j, i, neighbors);
	k = 0;
	untraversables = 0;
	while (k < 4)
	{
		i = neighbors[k].i;
		j = neighbors[k].j;
		if (game.map[i][j] == '1' ||
			(game.map[i][j] != '1' && mark_map[i][j] == 'F'))
			untraversables++;
		k++;
	}
	if (untraversables == 4)
		return (0);
	return (1);
}

int	valid_path_check(t_game game, char **mark_map)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
		{
			if (game.map[i][j] == 'P' && mark_map[i][j] == 'T')
				flag++;
			if (game.map[i][j] == 'E'
				&& check_exit(game, mark_map, j, i))
				flag++;
			j++;
		}
		i++;
	}
	if (flag == 2)
		return (destroy_map(mark_map), 1);
	return (destroy_map(mark_map), 0);
}
