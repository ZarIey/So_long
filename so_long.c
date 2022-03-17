/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:10:36 by ctardy            #+#    #+#             */
/*   Updated: 2022/03/16 10:34:23 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_so_long	game;

	if (argc != 2)
		return (0);
	fd_verif(argv[1]);
	ber_verif(argv[1]);
	ft_memset(&game, 0, sizeof(t_so_long));
	map_reader(&game, argv);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, (game.width * 64),
			(game.height * 64), "so_long");
	errors(&game);
	image_creator(&game);
	put_floor_map(&game);
	put_stuff_on_map(&game);
	mlx_hook(game.window, 2, (1L << 0), player_move, &game);
	mlx_hook(game.window, 17, (1L << 17), exit_game, &game);
	mlx_loop(game.mlx);
	free(&game);
	return (0);
}
