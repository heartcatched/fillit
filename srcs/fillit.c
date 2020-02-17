/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzoltan <wzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:57:51 by wzoltan           #+#    #+#             */
/*   Updated: 2020/02/15 20:31:00 by wzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			check_line_for_hash_n_dots(char *line)
{
	int		l;
	int		i;
	int		hash_count;

	i = 0;
	hash_count = 0;
	l = ft_strlen(line);
	while (line[i])
	{
		if (line[i] != '.' && line[i] != '#')
			ft_exit();
		if (line[i] == '#')
			hash_count++;
		i++;
	}
	if ((l != 4) || (hash_count > 4))
		ft_exit();
	return (hash_count);
}

void		kostyl(char *line)
{
	if (ft_strlen(line))
		ft_exit1(line);
	//free(line);
	ft_strdel(&line);
}

int			validity(int fd)
{
	int		str_count;
	int		hash_count;
	char	*line;

	line = NULL;
	while (1)
	{
		str_count = 0;
		hash_count = 0;
		while (str_count++ < 4 && get_next_line(fd, &line) != 0)
		{
			hash_count = hash_count + check_line_for_hash_n_dots(line);
			//free(line);
			ft_strdel(&line);
		}
		if (hash_count != 4)
			ft_exit();
		if (get_next_line(fd, &line) == 1)
			kostyl(line);
//			free(line);
		else
		{
			if (get_next_line(fd, &line) == 0)
				break;
		}

	}
	close(fd);
	return (0);
}

void		filling_mas(int *buf, int i, int str_count)
{
	static int j;

	j = 0;
	buf[j] = str_count;
	buf[j + 1] = i;
	j = j + 2;
}

int			*find_coord(int fd, int str_count)
{
	int		j;
	int		*buf;
	char	*line;
	int		i;

	j = 0;
	buf = NULL;
	buf = (int*)malloc(sizeof(int) * 8);
	while ((str_count < 4) && (get_next_line(fd, &line)))
	{
		i = 0;
		while (line[i])
		{
			if (line[i] == '#')
			{
				buf[j] = str_count;
				buf[j + 1] = i;
				j = j + 2;
			}
			i++;
		}
		str_count++;
		//free(line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (buf);
}
