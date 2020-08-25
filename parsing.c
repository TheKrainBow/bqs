/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 16:35:56 by magostin          #+#    #+#             */
/*   Updated: 2020/08/25 18:24:14 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void		ft_exit(void)
{
	ft_putstr("map error");
	exit(1);
}

int			is_n(char c)
{
	return ((c >= '0' && c <= '9'));
}

int			ft_check_line(char *line, t_data *data)
{
	while (line && *line)
	{
		if (*line != data->empty && *line != data->full)
			return (0);
		line++;
	}
	return (1);
}

int			ft_pars_map(int	fd, t_data *data)
{
	char	*line;
	int		i;
	int		ret;

	i = -1;
	data->line_n = 0;
	data->line_size = -1;
	ret = get_next_line(fd, &line);
	while (ret && is_n(line[++i]))
		data->line_n = data->line_n * 10 + line[i] - '0';
	data->empty = line[i];
	data->full = line[i + 1];
	data->fill = line[i + 2];
	if (line[i + 3])
		ft_exit();
	//free(line);
	if (!(data->map = malloc(sizeof(char *) * (data->line_n + 1))))
		ft_exit();
	i = -1;
	while (++i < data->line_n)
	{
		ret = get_next_line(fd, &data->map[i]);
		data->line_size = data->line_size == -1 ? ft_strlen(data->map[i]) : data->line_size;
		if (ft_strlen(data->map[i]) != data->line_size || ft_check_line(data->map[i], data))
			ft_exit();
	}
	if (ret && get_next_line(fd, &line) != -1)
		ft_exit();
}