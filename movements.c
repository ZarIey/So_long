/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:10:06 by ctardy            #+#    #+#             */
/*   Updated: 2022/03/16 06:13:07 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up_w(t_so_long *game)
{
	int	h;
	int	w;

	h = game->player.vertical;
	w = game->player.horizontal;
	if (game->map_init.map[h - 1][w] == '0'
		|| game->map_init.map[h - 1][w] == 'C')
	{
		if (game->map_init.map[h - 1][w] == 'C')
			nbr_collect(game);
		game->player.vertical--;
		update_map(w, h, game);
		current_field(w, h, game);
		game->steps++;
		ft_putstr(ft_itoa(game->steps));
	}
	else if (game->map_init.map[h - 1][w] == 'E')
	{
		game->player.vertical--;
		update_map(w, h, game);
		current_field(w, h, game);
		check_collect(game);
		game->steps++;
		ft_putstr(ft_itoa(game->steps));
	}
}

void	left_a(t_so_long *game)
{
	int	h;
	int	w;

	h = game->player.vertical;
	w = game->player.horizontal;
	if (game->map_init.map[h][w - 1] == '0'
		|| game->map_init.map[h][w - 1] == 'C')
	{
		if (game->map_init.map[h][w - 1] == 'C')
			nbr_collect(game);
		game->player.horizontal--;
		update_map(w, h, game);
		current_field(w, h, game);
		game->steps++;
		ft_putstr(ft_itoa(game->steps));
	}
	else if (game->map_init.map[h][w - 1] == 'E')
	{
		game->player.horizontal--;
		update_map(w, h, game);
		current_field(w, h, game);
		check_collect(game);
		game->steps++;
		ft_putstr(ft_itoa(game->steps));
	}
}

void	down_s(t_so_long *game)
{
	int	h;
	int	w;

	h = game->player.vertical;
	w = game->player.horizontal;
	if (game->map_init.map[h + 1][w] == '0'
		|| game->map_init.map[h + 1][w] == 'C')
	{
		if (game->map_init.map[h + 1][w] == 'C')
			nbr_collect(game);
		game->player.vertical++;
		update_map(w, h, game);
		current_field(w, h, game);
		game->steps++;
		ft_putstr(ft_itoa(game->steps));
	}
	else if (game->map_init.map[h + 1][w] == 'E')
	{
		game->player.vertical++;
		update_map(w, h, game);
		current_field(w, h, game);
		check_collect(game);
		game->steps++;
		ft_putstr(ft_itoa(game->steps));
	}
}

void	right_d(t_so_long *game)
{
	int	h;
	int	w;

	h = game->player.vertical;
	w = game->player.horizontal;
	if (game->map_init.map[h][w + 1] == '0'
		|| game->map_init.map[h][w + 1] == 'C')
	{
		if (game->map_init.map[h][w + 1] == 'C')
			nbr_collect(game);
		game->player.horizontal++;
		update_map(w, h, game);
		current_field(w, h, game);
		game->steps++;
		ft_putstr(ft_itoa(game->steps));
	}
	else if (game->map_init.map[h][w + 1] == 'E')
	{
		game->player.horizontal++;
		update_map(w, h, game);
		current_field(w, h, game);
		check_collect(game);
		game->steps++;
		ft_putstr(ft_itoa(game->steps));
	}
}

int	player_move(int keycode, t_so_long *game)
{
	if (keycode == 13)
		up_w(game);
	if (keycode == 0)
		left_a(game);
	if (keycode == 1)
		down_s(game);
	if (keycode == 2)
		right_d(game);
	if (keycode == 53)
		exit_game();
	return (0);
}
