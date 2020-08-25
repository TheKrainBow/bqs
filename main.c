/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 19:57:42 by magostin          #+#    #+#             */
/*   Updated: 2020/08/25 18:28:04 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putstr(char *str)
{
	write(1, str, 1);
	while (str && (*str++))
		write(1, str, 1);
	write(1, "\n", 1);
}

void	ft_fill_cells(int x, int y, t_data *data)
{
	int		k;
	int		up;
	int		left;

	k = 0;
	up = 1;
	left = 1;
	if (data->map[x][y] == data->empty)
	{
		data->cells[x][y].state = 0;
		data->cells[x][y].left = 0;
		data->cells[x][y].up = 0;
		while (left || up)
		{
			if (left && y - k >= 0 && data->map[x][y - k] == data->empty)
				data->cells[x][y].left += 1;
			else if (left)
				left = 0;
			if (up && x - k >= 0 && data->map[x - k][y] == data->empty)
				data->cells[x][y].up += 1;
			else if (up)
				up = 0;
			k++;
		}
	}
	else
	{
		data->cells[x][y].state = 1;
		data->cells[x][y].left = 0;
		data->cells[x][y].up = 0;
	}
	
}

void	ft_change_map(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (++i <= data->best_size)
	{
		j = -1;
		while (++j <= data->best_size)
			data->map[data->best_x + i][data->best_y + j] = data->fill;
	}
}

int		ft_bsq(t_data *data)
{
	int			x;
	int			y;
	int			i;

	x = -1;
	data->cells = malloc(sizeof(t_cell *) * (data->line_n));
	while (++x < data->line_n)
	{
		data->cells[x] = malloc(sizeof(t_cell) * (data->line_size));
		y = -1;
		while (++y < data->line_size)
			ft_fill_cells(x, y, data);
	}

	data->best_size = 0;
	data->best_x = 0;
	data->best_y = 0;
	x = -1;
	while (++x < data->line_n - data->best_size)
	{
		y = -1;
		while (++y < data->line_size - data->best_size)
		{
			if (data->cells[x][y].state == 0)
			{
				i = 0;
				while (x + i < data->line_n && y + i < data->line_size
				&& data->cells[x + i][y + i].state == 0
				&& i < data->cells[x + i][y + i].left
				&& i < data->cells[x + i][y + i].up)
					i++;
				i--;
				if (data->best_size < i)
				{
					data->best_size = i;
					data->best_x = x;
					data->best_y = y;
				}
			}
		}
	}
	ft_change_map(data);
	return (1);
}

void		ft_print_map(t_data *data)
{
	int		i;

	i = -1;
	while (++i < data->line_n)
		ft_putstr(data->map[i]);
}

int			main(int ac, char **av)
{
	int			i;
	int			fd;
	t_data		data;

	if (ac == 1)
	{
		ft_putstr("map error");
		exit(1);
	}


	i = 0;
	while (++i < ac)
	{
		fd = open(av[i], O_RDONLY);
		ft_pars_map(fd, &data);
		ft_bsq(&data);
		//ft_print_map(&data);
	}
}