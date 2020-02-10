/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_n_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzoltan <wzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:38:19 by wzoltan           #+#    #+#             */
/*   Updated: 2020/01/30 18:56:39 by wzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_tetris	*ft_create_elem(int *content, t_tetris *next)
{
	t_tetris	*elem;

	if (!(elem = (t_tetris*)malloc(sizeof(t_tetris))))
		return (0);
	else
	{
		elem->tet_id = content;
		elem->next = next;
	}
	return (elem);
}

t_tetris	*ft_create_node_inbegin(t_tetris *list, int *a, char c)
{
	t_tetris	*tmp;

	list = NULL;
	tmp = (t_tetris*)malloc(sizeof(t_tetris));
	if (tmp == NULL)
		ft_putstr("error");
	tmp->tet_id = a;
	tmp->c = c;
	tmp->next = NULL;
	return (tmp);
}

t_tetris	*ft_create_node_end(t_tetris *list, int *a, char c)
{
	t_tetris	*header;

	header = list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_node_inbegin(list, a, c);
	}
	else
	{
		list = ft_create_node_inbegin(list, a, c);
		return (list);
	}
	return (header);
}

void		ft_exit(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

void		ft_exit1(char *line)
{
	ft_putstr("error\n");
	free(line);
	exit(EXIT_FAILURE);
}
