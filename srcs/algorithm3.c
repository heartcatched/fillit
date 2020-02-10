/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzoltan <wzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:51:35 by cbriccan          #+#    #+#             */
/*   Updated: 2020/01/28 21:42:34 by wzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	insert(int *tet_id, char **grid, char c)
{
	int k;

	k = 0;
	while (k < 8)
	{
		grid[tet_id[k]][tet_id[k + 1]] = c;
		k = k + 2;
	}
}

void	clear(int *tet_id, char **grid)
{
	int k;

	k = 0;
	while (k < 8)
	{
		grid[tet_id[k]][tet_id[k + 1]] = '.';
		k = k + 2;
	}
}

void	shift_yx(int *tet_id, int y, int x)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (i % 2 == 0)
			tet_id[i] = tet_id[i] + x;
		else
		{
			tet_id[i] = tet_id[i] + y;
		}
		i++;
	}
}

void	copy(int *a, int *b)
{
	int i;

	i = 0;
	while (i < 8)
	{
		a[i] = b[i];
		i++;
	}
}

void	print(char **grid, int grid_size)
{
	int i;
	int j;

	i = 0;
	while (i < grid_size)
	{
		j = 0;
		while (j < grid_size)
		{
			ft_putchar(grid[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
