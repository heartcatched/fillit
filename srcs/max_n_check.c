#include "fillit.h"
#include <stdio.h>

int    min_x(int     *a)
{
    int     i;
    int     min;
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

int    min_y(int     *a)
{
    int     i;
    int     min;

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

void        shift(int   *a)
{
    int     minx;
    int     miny;
    int     i;

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

int     me(int *a, int b[8])
{
    int     i;
    i = 0;
    while (i < 8)
    {
        if (a[i] != b[i])
            return (0);
        i++;
    }
    return (1);
}
void    final_check(int *a)
{
    if (!((me(a,I)) || (me(a,I90)) || (me(a,O)) || (me(a,L)) || (me(a,L90)) || (me(a,L180)) || (me(a,L270)) || (me(a,J)) || (me(a,J90))  || (me(a,J180)) \
     || (me(a,J270)) || (me(a,T)) || (me(a,T90)) || (me(a,T180)) || (me(a,T270)) || (me(a,S)) || (me(a,S90)) || (me(a,Z)) || (me(a,Z90))))
    {
        ft_putstr("error");
        exit(0);
    }
}
