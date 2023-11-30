/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:47:14 by mawad             #+#    #+#             */
/*   Updated: 2023/11/15 19:19:31 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_image1(t_game game, int i, int j, int flag)
{
	if (game.map[i][j] == 'P' && (flag == 0 || flag == 2))
		mlx_put_image_to_window(game.mlx, game.win.mlx_win,
			game.album[2].img, j * DIM, i * DIM);
	if (game.map[i][j] == 'P' && flag == 1)
		mlx_put_image_to_window(game.mlx, game.win.mlx_win,
			game.album[3].img, j * DIM, i * DIM);
	if (game.map[i][j] == 'P' && flag == 3)
		mlx_put_image_to_window(game.mlx, game.win.mlx_win,
			game.album[4].img, j * DIM, i * DIM);
}

void	put_image2(t_game game, int i, int j, int flag)
{
	(void) flag;
	if (game.map[i][j] == 'E')
		mlx_put_image_to_window(game.mlx, game.win.mlx_win,
			game.album[5].img, j * DIM, i * DIM);
	if (game.map[i][j] == '0')
		mlx_put_image_to_window(game.mlx, game.win.mlx_win,
			game.album[6].img, j * DIM, i * DIM);
	if (game.map[i][j] == 'N' && game.enemy_dir == 0)
		mlx_put_image_to_window(game.mlx, game.win.mlx_win,
			game.en_alb[0].img, j * DIM, i * DIM);
	if (game.map[i][j] == 'N' && game.enemy_dir == 1)
		mlx_put_image_to_window(game.mlx, game.win.mlx_win,
			game.en_alb[1].img, j * DIM, i * DIM);
}

int	image_parser(t_game game)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (game.album[i].img == NULL)
			return (0);
		i++;
	}
	i = 0;
	while (i < 2)
	{
		if (game.en_alb[i].img == NULL)
			return (0);
		i++;
	}
	return (1);
}

void	load_enemy_images(t_game *game)
{
	game->en_alb[0].img = mlx_xpm_file_to_image(game->mlx,
			"Sprites/N_left.xpm", &game->album[0].img_width,
			&game->album[0].img_height);
	game->en_alb[1].img = mlx_xpm_file_to_image(game->mlx,
			"Sprites/N_right.xpm", &game->album[1].img_width,
			&game->album[1].img_height);
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
			"Sprites/Mega.xpm", &game->album[2].img_width,
			&game->album[2].img_height);
	game->album[3].img = mlx_xpm_file_to_image(game->mlx,
			"Sprites/Left.xpm", &game->album[3].img_width,
			&game->album[3].img_height);
	game->album[4].img = mlx_xpm_file_to_image(game->mlx,
			"Sprites/Back.xpm", &game->album[4].img_width,
			&game->album[4].img_height);
	game->album[5].img = mlx_xpm_file_to_image(game->mlx,
			"images/portal.xpm", &game->album[5].img_width,
			&game->album[5].img_height);
	game->album[6].img = mlx_xpm_file_to_image(game->mlx,
			"images/background.xpm", &game->album[6].img_width,
			&game->album[6].img_height);
	game->album[7].img = mlx_xpm_file_to_image(game->mlx,
			"images/Small_Coin.xpm", &game->album[7].img_width,
			&game->album[7].img_height);
}
