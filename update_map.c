/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:10:50 by ctardy            #+#    #+#             */
/*   Updated: 2022/03/15 08:40:30 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_map(int x, int y, t_so_long *game)
{
	int	h;
	int	w;

	h = game->player.vertical;
	w = game->player.horizontal;
	if (game->map_init.map[y][x] == 'E' || game->map_init.map[y][x] == 'X')
	{
		game->map_init.map[y][x] = 'E';
		game->map_init.map[h][w] = 'P';
	}
	else
	{
		game->map_init.map[y][x] = '0';
		if (game->map_init.map[h][w] == 'E')
			game->map_init.map[h][w] = 'X';
		else
			game->map_init.map[h][w] = 'P';
	}
}

void	current_field(int x, int y, t_so_long *game)
{
	int	h;
	int	w;

	h = game->player.vertical;
	w = game->player.horizontal;
	if (game->map_init.map[y][x] == 'E' || game->map_init.map[y][x] == 'X')
	{
		put_player(game, w, h);
		put_floor(game, x, y);
		put_exit(game, x, y);
	}
	else
	{
		put_floor(game, x, y);
		if (game->map_init.map[h][w] == 'E')
		{
			put_floor(game, x, y);
			put_exit(game, x, y);
		}
		else
			put_player(game, w, h);
	}
}
