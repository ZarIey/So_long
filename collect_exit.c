/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:08:27 by ctardy            #+#    #+#             */
/*   Updated: 2022/03/05 19:37:04 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	nbr_collect(t_so_long *game)
{
	int	col;

	game->collectible--;
	col = game->total_collect - game->collectible;
}

void	check_collect(t_so_long *game)
{
	if (game->collectible == 0)
	{
		exit (0);
	}
}
