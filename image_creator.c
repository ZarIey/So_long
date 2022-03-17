/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:53:13 by ctardy            #+#    #+#             */
/*   Updated: 2022/03/15 08:22:08 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_creator(t_so_long *game)
{
	game->path_wall = "./sprite/wall.xpm";
	game->wall_img = mlx_xpm_file_to_image(game->mlx, game->path_wall,
			&game->i, &game->j);
	game->path_player = "./sprite/player.xpm";
	game->player_img = mlx_xpm_file_to_image(game->mlx, game->path_player,
			&game->i, &game->j);
	game->path_floor = "./sprite/floor.xpm";
	game->floor_img = mlx_xpm_file_to_image(game->mlx, game->path_floor,
			&game->i, &game->j);
	game->path_collectible = "./sprite/collectible.xpm";
	game->collect_img = mlx_xpm_file_to_image(game->mlx, game->path_collectible,
			&game->i, &game->j);
	game->path_exit = "./sprite/exit.xpm";
	game->exit_img = mlx_xpm_file_to_image(game->mlx, game->path_exit,
			&game->i, &game->j);
	return ;
}
