/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 20:13:32 by magostin          #+#    #+#             */
/*   Updated: 2020/08/26 16:40:55 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include "get_next_line.h"

typedef struct		s_cell
{
	int				state;
	int				left;
	int				up;
}					t_cell;

typedef struct		s_data
{
	int				best_x;
	int				best_y;
	int				best_size;
	int				line_size;
	int				line_n;
	char			empty;
	char			full;
	char			fill;
	char			**map;
	t_cell			**cells;
}					t_data;

void				ft_pars_map(int	fd, t_data *data);
void				ft_putstr(char *str);

#endif