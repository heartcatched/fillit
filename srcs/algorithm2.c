/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzoltan <wzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:43:53 by cbriccan          #+#    #+#             */
/*   Updated: 2020/02/15 20:46:04 by wzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		floor_of_sqrt(int n)
{
	int i;

	i = 1;
	while (i * i < n)
		i++;
	return (i - 1);
}

int		start_size(t_tetris *list)
{
	int n;

	n = 1;
	while (list->next != NULL)
	{
		list = list->next;
		n++;
	}
	return (2 * floor_of_sqrt(n));
}

void	solution(t_tetris *list)
{
	char	**grid;
	int		size;

	size = start_size(list);
	grid = create_grid(size);
	while (!(exempt(grid, list, size)))
	{
		free_grid(grid, size);
		size++;
		grid = create_grid(size);
	}
	print(grid, size);
	free_grid(grid, size);
	free_list(list);
	exit(EXIT_SUCCESS);
}

int		exempt(char **grid, t_tetris *list, int grid_size)
{
	int		x;
	int		y;
	int		*tmp;

	tmp = (int*)malloc(sizeof(int) * 8);
	x = 0;
	y = 0;
	while (x < grid_size)
	{
		y = 0;
		while (y < grid_size)
		{
			copy(tmp, list->tet_id);
			shift_yx(tmp, y, x);
			if (insert_n_clear(tmp, list, grid, grid_size))
				return (1);
			y++;
		}
		x++;
	}
	free(tmp);
	return (0);
}

int		insert_n_clear(int *tet_id, t_tetris *list, char **grid, int grid_size)
{
	if (!(collision(grid, grid_size, tet_id)))
	{
		insert(tet_id, grid, list->c);
		if (list->next == NULL)
		{
			free(tet_id);
			return (1);
		}
		if (exempt(grid, list->next, grid_size))
		{
			free(tet_id);
			return (1);
		}
		clear(tet_id, grid);
	}
	return (0);
}
