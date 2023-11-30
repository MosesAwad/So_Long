/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 21:44:54 by mawad             #+#    #+#             */
/*   Updated: 2023/11/14 22:47:50 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (game->album[i].img == NULL)
		{
			i++;
			continue ;
		}
		mlx_destroy_image(game->mlx, game->album[i++].img);
	}
	i = 0;
	while (i < 2)
	{
		if (game->en_alb[i].img == NULL)
		{
			i++;
			continue ;
		}
		mlx_destroy_image(game->mlx, game->en_alb[i++].img);
	}
}

void	destroy_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	destroy_game_pre(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win.mlx_win);
	destroy_map(game->map);
	exit(0);
}

int	destroy_game_post(t_game *game)
{
	if (game->win_check == 0)
		ft_printf("Game has exited\n");
	else if (game->win_check == 1)
		ft_printf("Congrats! You have won\n");
	destroy_images(game);
	mlx_destroy_window(game->mlx, game->win.mlx_win);
	destroy_map(game->map);
	exit(0);
}
