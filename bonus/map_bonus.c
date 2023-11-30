/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:34:35 by mawad             #+#    #+#             */
/*   Updated: 2023/11/15 21:12:28 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		ft_printf("%s\n", map[i++]);
}

void	ft_draw_map(t_game game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
		{
			if (game.map[i][j] != '1')
				mlx_put_image_to_window(game.mlx, game.win.mlx_win,
					game.album[6].img, j * DIM, i * DIM);
			else
				mlx_put_image_to_window(game.mlx, game.win.mlx_win,
					game.album[0].img, j * DIM, i * DIM);
			j++;
		}
		i++;
	}
}

void	ft_draw_tiles(t_game game, int flag)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
		{
			put_image1(game, i, j, flag);
			put_image2(game, i, j, flag);
			j++;
		}
		i++;
	}
}

char	**get_map(int fd)
{
	char	**map;
	char	*buffer;
	int		i;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (9999));
	buffer = get_next_line(fd);
	if (!map || !buffer)
		return (close(fd), NULL);
	map[i] = (char *)malloc(sizeof(char) * (ft_strlen(buffer) + 1));
	ft_strlcpy(map[i++], buffer, (ft_strlen(buffer) + 1));
	free(buffer);
	while (buffer != NULL)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
		{
			map[i] = NULL;
			break ;
		}
		map[i] = (char *)malloc(1 * (ft_strlen(buffer) + 1));
		ft_strlcpy(map[i++], buffer, (ft_strlen(buffer) + 1));
		free(buffer);
	}
	return (close(fd), map);
}
