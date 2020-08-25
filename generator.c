/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 17:27:29 by magostin          #+#    #+#             */
/*   Updated: 2020/08/25 17:38:52 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define SIZE_MAP_X 10000
#define SIZE_MAP_Y 10000
#define CHAR_EMPTY '.'
#define CHAR_FULL 'o'
#define CHAR_FILL 'X'
#define DENSITY 0.1

int		random_map(void)
{
	char		**map;
	int			x;
	int			y;
	int			fd;

	fd = open("RANDOM_file", O_RDWR);
	srandom(time(NULL));
	map = malloc(sizeof(char *) * (SIZE_MAP_X + 1));
	x = -1;
	dprintf(fd, "%d%c%c%c\n", SIZE_MAP_X, CHAR_EMPTY, CHAR_FULL, CHAR_FILL);
	while (++x < SIZE_MAP_X)
	{
		map[x] = malloc(sizeof(char) * (SIZE_MAP_Y + 1));
		y = -1;
		while (++y < SIZE_MAP_X)
			map[x][y] = (random() % 1000 < DENSITY * 1000) ? CHAR_FULL : CHAR_EMPTY;
		map[x][y] = 0;
		dprintf(fd, x != SIZE_MAP_X - 1 ? "%s\n" : "%s", map[x]);
	}
	map[x] = NULL;
	printf("FILE GENERATED\n");
	close(fd);
	return (1);
}

int		main()
{
	random_map();
}