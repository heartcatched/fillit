/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbriccan <cbriccan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:40:53 by wzoltan           #+#    #+#             */
/*   Updated: 2020/02/17 15:18:20 by cbriccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_tetris	*check_structure(int fd)
{
	int			k;
	t_tetris	*list;
	int			*buf;
	char		*line;
	int			str_count;

	k = 0;
	list = NULL;
	while (1)
	{
		str_count = 0;
		buf = find_coord(fd, str_count);
		shift(buf);
		final_check(buf);
		list = ft_create_node_end(list, buf, k + 'A');
		k > 27 ? ft_exit() : k++;
		if (!(get_next_line(fd, &line)))
			break ;
		buf = NULL;
		free(buf);
		ft_strdel(&line);
	}
	return (list);
}

void		final_check(int *a)
{
	if (correct_1(a) == 0 && correct_2(a) == 0)
		ft_exit();
}

int			main(int argc, char **argv)
{
	t_tetris		*list;
	int				fd;

	fd = 0;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_exit();
	validity(fd);
	fd = open(argv[1], O_RDONLY);
	list = check_structure(fd);
	solution(list);
}

void		free_list(t_tetris *list)
{
	t_tetris *tmp;

	while (list->next != NULL)
	{
		tmp = list;
		free(list->tet_id);
		list = list->next;
		free(tmp);
	}
}
