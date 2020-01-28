/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbriccan <cbriccan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:54:55 by cbriccan          #+#    #+#             */
/*   Updated: 2020/01/28 21:01:47 by cbriccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int		max_x(int *a)
{
	int i;
	int max;

	i = 0;
	max = a[0];
	while (i < 8)
	{
		if (a[i] > max)
			max = a[i];
		i = i + 2;
	}
	return (max);
}

int		max_y(int *a)
{
	int i;
	int max;

	i = 1;
	max = a[1];
	while (i < 8)
	{
		if (a[i] > max)
			max = a[i];
		i = i + 2;
	}
	return (max);
}

int		collision_grid(int grid_size, int *tet_id)
{
	if (max_x(tet_id) >= grid_size || max_y(tet_id) >= grid_size)
		return (1);
	return (0);
}

int		collision_piece(char **grid, int *tet_id)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (grid[tet_id[i]][tet_id[i + 1]] != '.')
			return (1);
		i = i + 2;
	}
	return (0);
}

int		collision(char **grid, int grid_size, int *tet_id)
{
	return (collision_grid(grid_size, tet_id) || collision_piece(grid, tet_id));
}
