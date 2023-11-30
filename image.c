/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:47:14 by mawad             #+#    #+#             */
/*   Updated: 2023/11/14 22:48:47 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game game, int i, int j, int flag)
{
	if (game.map[i][j] == '1')
		mlx_put_image_to_window(game.mlx, game.win.mlx_win,
			game.album[0].img, j * DIM, i * DIM);
	if (game.map[i][j] == 'C')
		mlx_put_image_to_window(game.mlx, game.win.mlx_win,
			game.album[1].img, j * DIM, i * DIM);
	if (game.map[i][j] == 'P' && flag == 0)
		mlx_put_image_to_window(game.mlx, game.win.mlx_win,
			game.album[2].img, j * DIM, i * DIM);
	if (game.map[i][j] == 'P' && flag == 1)
		mlx_put_image_to_window(game.mlx, game.win.mlx_win,
			game.album[3].img, j * DIM, i * DIM);
	if (game.map[i][j] == 'E')
		mlx_put_image_to_window(game.mlx, game.win.mlx_win,
			game.album[4].img, j * DIM, i * DIM);
	if (game.map[i][j] == '0')
		mlx_put_image_to_window(game.mlx, game.win.mlx_win,
			game.album[5].img, j * DIM, i * DIM);
}

int	image_parser(t_game game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (game.album[i].img == NULL)
			return (0);
		i++;
	}
	return (1);
}

void	load_images(t_game *game)
{
	game->album[0].img = mlx_xpm_file_to_image(game->mlx,
			"images/block_brick.xpm", &game->album[0].img_width,
			&game->album[0].img_height);
	game->album[1].img = mlx_xpm_file_to_image(game->mlx,
			"images/gold_coin.xpm", &game->album[1].img_width,
			&game->album[1].img_height);
	game->album[2].img = mlx_xpm_file_to_image(game->mlx,
			"images/megaman.xpm", &game->album[2].img_width,
			&game->album[2].img_height);
	game->album[3].img = mlx_xpm_file_to_image(game->mlx,
			"images/left.xpm", &game->album[3].img_width,
			&game->album[3].img_height);
	game->album[4].img = mlx_xpm_file_to_image(game->mlx,
			"images/portal.xpm", &game->album[4].img_width,
			&game->album[4].img_height);
	game->album[5].img = mlx_xpm_file_to_image(game->mlx,
			"images/background.xpm", &game->album[5].img_width,
			&game->album[5].img_height);
}
