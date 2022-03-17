/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:05:38 by ctardy            #+#    #+#             */
/*   Updated: 2022/03/17 06:08:45 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_error_l(t_so_long *game)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	while (h < game->height)
	{
		if (game->map_init.map[h][w] != '1')
			return (-1);
		h++;
	}
	h = 0;
	w = 0;
	while (w < game->width)
	{
		if (game->map_init.map[h][w] != '1')
			return (-1);
		w++;
	}
	return (0);
}

int	wall_error_r(t_so_long *game)
{
	int	h;
	int	w;

	h = 0;
	w = game->width - 1;
	while (h < game->height)
	{
		if (game->map_init.map[h][w] != '1')
			return (-1);
		h++;
	}
	h = game->height - 1;
	w = 0;
	while (w < game->width)
	{
		if (game->map_init.map[h][w] != '1')
			return (-1);
		w++;
	}
	return (0);
}

int	check_tiles(t_so_long *game)
{
	int		h;
	int		w;
	char	c;

	h = 0;
	w = 0;
	while (h < game->height)
	{
		while (w < game->width)
		{
			c = game->map_init.map[h][w];
			if (c != '0' && c != '1' && c != 'P' && c != 'C' && c != 'E')
				return (-1);
			w++;
		}
		h++;
		w = 0;
	}
	return (0);
}

int	check_mandatory(t_so_long *game)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	while (h < game->height)
	{
		while (w < game->width)
		{
			if (game->map_init.map[h][w] == 'P')
				game->map_err.play++;
			else if (game->map_init.map[h][w] == 'C')
				game->map_err.col++;
			else if (game->map_init.map[h][w] == 'E')
				game->map_err.ex++;
			w++;
		}
		h++;
		w = 0;
	}
	if (game->map_err.play != 1 || game->map_err.col < 1
		|| game->map_err.ex < 1)
		return (-1);
	else
		return (0);
}

void	errors(t_so_long *game)
{
	if (wall_error_r(game) == -1 || wall_error_l(game) == -1
		|| check_mandatory(game) == -1 || check_tiles(game) == -1
		|| is_it_square(game) == -1)
	{
		write(1, "Error\nMap format incorrect !", 29);
		exit (0);
	}
}
