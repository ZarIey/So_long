/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:08:06 by ctardy            #+#    #+#             */
/*   Updated: 2022/03/15 08:28:06 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_floor(t_so_long *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->floor_img,
		x * 64, y * 64);
}

void	put_wall(t_so_long *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->wall_img,
		x * 64, y * 64);
}

void	put_player(t_so_long *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->player_img,
		x * 64, y * 64);
}

void	put_collectible(t_so_long *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->collect_img,
		x * 64, y * 64);
}

void	put_exit(t_so_long *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->exit_img,
		x * 64, y * 64);
}
