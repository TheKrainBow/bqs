/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 17:27:29 by magostin          #+#    #+#             */
/*   Updated: 2020/08/25 18:43:39 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define CHAR_EMPTY '.'
#define CHAR_FULL 'o'
#define CHAR_FILL 'X'

int		random_map(char *str, double density, int size)
{
	char		**map;
	int			x;
	int			y;
	int			fd;

	fd = open(str, O_RDWR);
	srandom(time(NULL));
	map = malloc(sizeof(char *) * (size + 1));
	x = -1;
	dprintf(fd, "%d%c%c%c\n", size, CHAR_EMPTY, CHAR_FULL, CHAR_FILL);
	while (++x < size)
	{
		map[x] = malloc(sizeof(char) * (size + 1));
		y = -1;
		while (++y < size)
			map[x][y] = (random() % 1000 < density * 1000) ? CHAR_FULL : CHAR_EMPTY;
		map[x][y] = 0;
		dprintf(fd, x != size - 1 ? "%s\n" : "%s", map[x]);
	}
	map[x] = NULL;
	printf("FILE GENERATED\n");
	close(fd);
	return (1);
}

int		main(int ac, char **av)
{
	random_map(av[1], (double)((double)atoi(av[2]) / 100), atoi(av[3]));
}