/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_n_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbriccan <cbriccan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 22:26:55 by cbriccan          #+#    #+#             */
/*   Updated: 2020/01/30 22:57:07 by cbriccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		min_x(int *a)
{
	int i;
	int min;

	min = a[0];
	i = 0;
	while (i < 8)
	{
		if (a[i] < min)
			min = a[i];
		i = i + 2;
	}
	return (min);
}

int		min_y(int *a)
{
	int i;
	int min;

	min = a[1];
	i = 1;
	while (i < 8)
	{
		if (a[i] < min)
			min = a[i];
		i = i + 2;
	}
	return (min);
}

void	shift(int *a)
{
	int minx;
	int miny;
	int i;

	minx = min_x(a);
	miny = min_y(a);
	i = 0;
	while (i < 8)
	{
		if (i % 2 == 0)
			a[i] = a[i] - minx;
		else
		{
			a[i] = a[i] - miny;
		}
		i++;
	}
}

int		correct_1(int *a)
{
	if ((a[0] == 0 && a[1] == 0 && a[2] == 1 && a[3] == 0
	&& a[4] == 2 && a[5] == 0 && a[6] == 3 && a[7] == 0)
	|| (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 1
	&& a[4] == 0 && a[5] == 2 && a[6] == 0 && a[7] == 3)
	|| (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 1
	&& a[4] == 1 && a[5] == 0 && a[6] == 1 && a[7] == 1)
	|| (a[0] == 0 && a[1] == 0 && a[2] == 1 && a[3] == 0
	&& a[4] == 2 && a[5] == 0 && a[6] == 2 && a[7] == 1)
	|| (a[0] == 0 && a[1] == 2 && a[2] == 1 && a[3] == 0
	&& a[4] == 1 && a[5] == 1 && a[6] == 1 && a[7] == 2)
	|| (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 1
	&& a[4] == 1 && a[5] == 1 && a[6] == 2 && a[7] == 1)
	|| (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 1
	&& a[4] == 0 && a[5] == 2 && a[6] == 1 && a[7] == 0)
	|| (a[0] == 0 && a[1] == 1 && a[2] == 1 && a[3] == 1
	&& a[4] == 2 && a[5] == 0 && a[6] == 2 && a[7] == 1)
	|| (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 1
	&& a[4] == 0 && a[5] == 2 && a[6] == 1 && a[7] == 2))
		return (1);
	else
		return (0);
}

int		correct_2(int *a)
{
	if ((a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 1
	&& a[4] == 1 && a[5] == 0 && a[6] == 2 && a[7] == 0)
	|| (a[0] == 0 && a[1] == 0 && a[2] == 1 && a[3] == 0
	&& a[4] == 1 && a[5] == 1 && a[6] == 1 && a[7] == 2)
	|| (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 1
	&& a[4] == 0 && a[5] == 2 && a[6] == 1 && a[7] == 1)
	|| (a[0] == 0 && a[1] == 0 && a[2] == 1 && a[3] == 0
	&& a[4] == 1 && a[5] == 1 && a[6] == 2 && a[7] == 0)
	|| (a[0] == 0 && a[1] == 1 && a[2] == 1 && a[3] == 0
	&& a[4] == 1 && a[5] == 1 && a[6] == 1 && a[7] == 2)
	|| (a[0] == 0 && a[1] == 1 && a[2] == 1 && a[3] == 0
	&& a[4] == 1 && a[5] == 1 && a[6] == 2 && a[7] == 1)
	|| (a[0] == 0 && a[1] == 1 && a[2] == 0 && a[3] == 2
	&& a[4] == 1 && a[5] == 0 && a[6] == 1 && a[7] == 1)
	|| (a[0] == 0 && a[1] == 0 && a[2] == 1 && a[3] == 0
	&& a[4] == 1 && a[5] == 1 && a[6] == 2 && a[7] == 1)
	|| (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 1
	&& a[4] == 1 && a[5] == 1 && a[6] == 1 && a[7] == 2)
	|| (a[0] == 0 && a[1] == 1 && a[2] == 1 && a[3] == 0
	&& a[4] == 1 && a[5] == 1 && a[6] == 2 && a[7] == 0))
		return (1);
	else
		return (0);
}
