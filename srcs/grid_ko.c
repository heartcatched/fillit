/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_ko.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbriccan <cbriccan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:49:04 by cbriccan          #+#    #+#             */
/*   Updated: 2020/02/15 12:36:36 by cbriccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	**create_grid(int grid_size)
{
	char	**tm;
	int		i;
	int		j;

	if (!(tm = (char**)malloc(sizeof(char*) * grid_size + 1)))
		return (0);
	i = 0;
	while (i < grid_size)
	{
		if (!(tm[i] = (char*)malloc(sizeof(char) * grid_size + 1)))
			return (0);
		j = 0;
		while (j < grid_size)
		{
			tm[i][j] = '.';
			j++;
		}
		tm[i][j] = '\0';
		i++;
	}
	return (tm);
}

void	free_grid(char **grid, int grid_size)
{
	int i;

	i = 0;
	while (i < grid_size)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	free_t_tetris(t_tetris *stack)
{
	t_tetris *tmp;

	while (stack->next != NULL)
	{
		tmp = stack;
		stack= stack->next;
		free(tmp->tet_id);
		free(tmp);
	}
}
