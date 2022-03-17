/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 07:57:43 by ctardy            #+#    #+#             */
/*   Updated: 2022/03/15 08:16:00 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_it_square(t_so_long *game)
{
	int	i;
	int	w;

	w = ft_strlen(game->map_init.map[0]);
	i = 1;
	while (i < game->height)
	{
		if ((int)ft_strlen(game->map_init.map[i]) != w)
			return (-1);
		i++;
	}
	return (0);
}
