/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:53:40 by mawad             #+#    #+#             */
/*   Updated: 2023/11/14 22:47:47 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	player_eat(t_game *game)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				flag = 1;
			j++;
		}
		i++;
	}
	if (flag == 0)
		return (0);
	return (1);
}

void	coin_anim1(t_game *game)
{
	int			i;
	int			j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->win.mlx_win,
					game->album[6].img, j * DIM, i * DIM);
				mlx_put_image_to_window(game->mlx, game->win.mlx_win,
					game->album[1].img, j * DIM, i * DIM);
			}
			j++;
		}
		i++;
	}
	game->coin_flash++;
}

void	coin_anim2(t_game *game)
{
	int			i;
	int			j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->win.mlx_win,
					game->album[6].img, j * DIM, i * DIM);
				mlx_put_image_to_window(game->mlx, game->win.mlx_win,
					game->album[7].img, j * DIM, i * DIM);
			}
			j++;
		}
		i++;
	}
	game->coin_flash = 0;
}
