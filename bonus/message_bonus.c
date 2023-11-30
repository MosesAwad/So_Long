/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:35:21 by mawad             #+#    #+#             */
/*   Updated: 2023/11/14 22:48:17 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	game_checker(t_game game)
{
	char	**marked_map;

	if (game.player_check == 0 || game.player_check > 1)
		return (0);
	if (game.coin_check == 0)
		return (1);
	if (game.exit_check == 0 || game.exit_check > 1)
		return (2);
	if (map_rules1(game) == 0)
		return (3);
	if (map_rules2(game) == 0)
		return (4);
	if (wall_rules1(game) == 0 || wall_rules2(game) == 0)
		return (5);
	marked_map = mark_map(game.map);
	dfs(&game, marked_map, game.player.pos_x / DIM, game.player.pos_y / DIM);
	if (valid_path_check(game, marked_map) == 0)
		return (6);
	return (7);
}

void	message(t_game *game)
{
	int	checker;

	checker = game_checker(*game);
	if (checker == 0)
		ft_printf("Error\nCheck if more than one player or no player!\n");
	if (checker == 1)
		ft_printf("Error\nBruh, no coin!\n");
	if (checker == 2)
		ft_printf("Error\nBruh, must have at least and only one exit\n");
	if (checker == 3)
		ft_printf("Error\nBruh, map is not rectangular\n");
	if (checker == 4)
		ft_printf("Error\nBruh, wrong map element inserted\n");
	if (checker == 5)
		ft_printf("Error\nBruh, map not surrounded by walls\n");
	if (checker == 6)
		ft_printf("Error\nBruh, invalid map path (player cannot exit!)\n");
	if (checker != 7)
		destroy_game_pre(game);
}

void	imgmsg_loadcheck(t_game *game)
{
	if (image_parser(*game) == 0)
	{
		ft_printf("Error\nBruh, check all image files are present\n");
		destroy_images(game);
		mlx_destroy_window(game->mlx, game->win.mlx_win);
		destroy_map(game->map);
		exit(0);
	}
}
