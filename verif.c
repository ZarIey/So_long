/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:07:37 by ctardy            #+#    #+#             */
/*   Updated: 2022/03/17 06:15:49 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fd_verif(char *str)
{
	int		fd;
	int		fd2;
	char	buf[1];

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\nMap not found !", 21);
		exit (0);
	}
	fd2 = read(fd, buf, 1);
	if (fd2 < 0)
	{
		write(1, "Error\nMap is a directory !", 26);
		exit (0);
	}
	return ;
}

void	msg_exit(void)
{
	write(1, "Error\nMap has a wrong extension !", 33);
	exit(0);
}

void	ber_verif(char *str)
{
	int		i;
	char	*inter;

	i = 0;
	while (str[i])
		i++;
	inter = &str[(i - 4)];
	if ((ft_strncmp(inter, ".ber", 4) != 0))
		msg_exit();
	return ;
}
