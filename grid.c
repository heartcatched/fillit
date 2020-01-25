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
	//print(tm, grid_size);
	return (tm);
}
