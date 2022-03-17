/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:03:46 by ctardy            #+#    #+#             */
/*   Updated: 2022/03/15 11:32:49 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line_map(char **argv)
{
	int		count;
	int		fd;
	char	*str;

	count = 0;
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		str = (get_next_line(fd));
		if (!str)
			break ;
		free(str);
		count++;
	}
	close(fd);
	return (count);
}

void	map_reader(t_so_long *game, char **argv)
{
	int		count;
	int		fd;
	char	*str;

	count = count_line_map(argv);
	fd = open(argv[1], O_RDONLY);
	game->map_init.map = (char **)malloc(count * sizeof(char *));
	count = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		game->map_init.map[count] = str;
		count++;
	}
	close(fd);
	game->height = count;
	game->width = ft_strlen(game->map_init.map[0]);
	return ;
}

void	put_floor_map(t_so_long *game)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	while (h < game->height)
	{
		while (w < game->width)
		{
			put_floor(game, w, h);
			w++;
		}
		h++;
		w = 0;
	}
	return ;
}

void	put_stuff_on_map(t_so_long *game)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	while (h < game->height)
	{
		while (w < game->width)
		{
			if (game->map_init.map[h][w] == '1')
				put_wall(game, w, h);
			if (game->map_init.map[h][w] == 'C')
				set_collectible(game, w, h);
			if (game->map_init.map[h][w] == 'P')
				set_player(game, w, h);
			if (game->map_init.map[h][w] == 'E')
				put_exit(game, w, h);
			w++;
		}
	h++;
	w = 0;
	}
}
