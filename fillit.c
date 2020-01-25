#include "fillit.h"
#include <stdio.h>

/*void    empty_mas(int *a, int n)
{
    int     i;

    while (i < n)
*/


void    print_mas(int *a, int n)
{
    int     i;

    i = 0;
    while (i < n)
    {
        ft_putchar(a[i] + '0');
        ft_putchar(' ');

        i++;
    }
    ft_putchar('\n');
}

void	ft_print_list(t_tetris *list)
{
    int     i;
    int     *a;

    i = 0;
	while (list)
	{
        i = 0;
        a = list->tet_id;
        /*printf("before printing list ");
        print_mas(list->tet_id, 8);*/
        while (i < 8)
        {
		    printf("%d ", a[i]);
            i++;
        }
        printf("     %c\n", list->c);
		list = list->next;
	}
}

t_tetris	*ft_create_node_inbegin(t_tetris *list, int *a, char c)
{
	t_tetris	*tmp;

	tmp = (t_tetris*)malloc(sizeof(t_tetris));
	if (tmp == NULL)
		printf("error");
    //print_mas(a, 8);
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
	return(header);
}


int     validity(void)
{
    int     l;
    int     str_count;
    int     hash_count;
    char    *line;
    int     i;
    int     g = 10;
    int     fd;

    fd = open("file", O_RDONLY);
    line = NULL;
    while (1)
    {
        str_count = 0;
        hash_count = 0;
        while (str_count < 4 && get_next_line(fd, &line) != 0)
        {
            l  = ft_strlen(line);
            i = 0;
            while (line[i])
            {
                if (line[i] != '.' && line[i] != '#')
                {
                    printf("error\n");
                    exit(0);
                }
                if (line[i] == '#')
                    hash_count++;
                i++;
            }
            if ((l != 4) || (hash_count > 4))
            {
                printf("error\n");
                exit(0);
            }
            free(line);
            str_count++;
        }
        if (hash_count != 4)
        {
            printf("error\n");
                exit(0);
        }
        if (g == 0)
        {
            printf("error\n");
            exit(0);
        }
        g = get_next_line(fd, &line);
        if (g == 1)
        {
            if (ft_strlen(line))
            {
                printf("error\n");
                free(line);
                exit(0);
            }
        }
        else
        {
            if (g == 0)
                break;
        }
    }
    printf("good\n");
    close(fd);
    return (0);
}

t_tetris    *ft_create_elem(int *content, t_tetris *next)
{
    t_tetris    *elem;

    if (!(elem = (t_tetris*)malloc(sizeof(t_tetris))))
        return (0);
    else
    {
        elem->tet_id = content;
        elem->next = next;
    }
    return (elem);
}
t_tetris      *check_structure(void)
{
    int     fd;
    char     *line;
    int     str_count;
    int     i;
    int     *buf;
    int     j;
    int     k = 0;
    int     m = 0;
    t_tetris    *list;

    list = NULL;
    fd = open("file", O_RDONLY);
    while (1)
    {
        buf = NULL;
        buf = (int*)malloc(sizeof(int) * 8);
        //print_mas(buf, 8);
        j = 0;
        str_count = 0;
        while ((str_count < 4) && (get_next_line(fd, &line)))
        {
            i = 0;
            while (line[i])
            {
                if (line[i] == '#')
                {
                    buf[j] = str_count;
                    buf[j + 1] = i;
                    j = j + 2;
                }
                i++;
            }
            str_count++;
            free(line);
        }
        shift(buf);
        final_check(buf);
        list = ft_create_node_end(list,buf, k + 'A');
        k++;
        //print_mas(buf, 8);
        if (!(get_next_line(fd, &line)))
            break;
        line = NULL;
        /*printf("tetramino coordinates\n");
        m = 0;
            while (m < 8)
            {
                printf("%d ", buf[m]);
                m++;
            }
            printf("\n");*/
        //free(buf);
    }
    //free(line);
    ft_print_list(list);
    return (list);
}

int     main(void)
{
    int     i = 0;
    t_tetris      *list;

    validity();
    list = check_structure();
    //ft_print_list(list);
    solution(list);
    return (0);
}
