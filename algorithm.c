#include "fillit.h"
#include <stdio.h>

int     max_x(int *a)
{
    int     i;
    int     max;

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

int     max_y(int *a)
{
    int     i;
    int     max;

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

int     collision_grid(int grid_size, int *tet_id)
{
    if (max_x(tet_id) > grid_size || max_y(tet_id) > grid_size)
        return (1);
    return (0);
}

int     collision_piece(char **grid, int *tet_id)
{
    int     i;

    i = 0;
    while (i < 8)
    {
        if (grid[tet_id[i]][tet_id[i + 1]] != '.')
            return (1);
        i = i + 2;
    }
    return (0);
}

int     collision(char **grid, int grid_size, int *tet_id)
{
    return (collision_grid(grid_size, tet_id) || collision_piece(grid, tet_id));
}
int     floor_of_sqrt(int n)
{
    int     i;

    i = 1;
    while (i * i < n)
        i++;
    return (i);
}
int     start_size(t_tetris *list)
{
    int     n;

    n = 1;
    while (list->next)
        n++;

    return (2 * floor_of_sqrt(n));
}

void    solution(t_tetris *list)
{
    char    **grid;
    int     size;


    //size = start_size(list);
    size = 3;
    grid = create_grid(size);
    while (!(exempt(grid, list, size)))
    {
        free(grid);
        size++;
        //printf("a");
        grid = create_grid(size);
    }
    print(grid);
}

int     exempt(char **grid, t_tetris *list, int grid_size)
{
    int     x;
    int     y;
    int     *tmp;
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
            print_mas(tmp, 8);
            if (insert_n_clear(tmp, list, grid, grid_size))
                return (1);
            y++;
        }
        x++;
    }
    return (0);
}

int     insert_n_clear(int  *tet_id, t_tetris *list, char **grid, int grid_size)
{
    if (!(collision(grid, grid_size, tet_id)))
    {
        insert(tet_id, grid, grid_size, list->c);
        print(grid);
        /*if (exempt(grid, list->next, grid_size))
        {
            free(tet_id);
            return (1);
        }
        clear(tet_id, grid, grid_size);*/return(1);
    }
    return (0);
}

void    insert(int *tet_id, char **grid, int grid_size, char c)
{
    int     k;

    //print_mas(tet_id, 8);
    k = 0;
    while (k < 8)
    {
        grid[tet_id[k]][tet_id[k + 1]] = c;
        k = k + 2;
    }
}

void    clear(int *tet_id, char **grid, int grid_size)
{
        int     k;

    k = 0;
    while (k < 8)
    {
        grid[tet_id[k]][tet_id[k + 1]] = '.';
        k = k + 2;
    }
}
void    shift_yx(int *tet_id, int y, int x)
{
    int     i;

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

void    copy(int *a, int *b)
{
    int     i;

    i = 0;
    while (i < 8)
    {
        a[i] = b[i];
        i++;
    }
}

void    print(char **grid)
{
    int     i;
    int     j;

    i = 0;
    while (grid[i])
    {
        j = 0;
        while (grid[i][j])
        {
            ft_putchar(grid[i][j]);
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}
