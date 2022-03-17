/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_and_collect.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:04:19 by ctardy            #+#    #+#             */
/*   Updated: 2022/03/15 08:28:31 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player(t_so_long *game, int w, int h)
{
	game->player.horizontal = w;
	game->player.vertical = h;
	put_player(game, w, h);
	return ;
}

void	set_collectible(t_so_long *game, int w, int h)
{
	game->total_collect++;
	game->collectible++;
	put_collectible(game, w, h);
	return ;
}
