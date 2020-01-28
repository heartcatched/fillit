#include "fillit.h"
#include <stdio.h>

/*void    empty_mas(int *a, int n)
{
    int     i;

    while (i < n)
*/



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

    list = NULL;
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

void    ft_exit(void)
{
    ft_putstr("error\n");
    exit(EXIT_FAILURE);
}

void    ft_exit1(char *line)
{
    ft_putstr("error\n");
    free(line);
    exit(EXIT_FAILURE);
}
int    check_line_for_hash_n_dots(char *line)
{
    int     l;
    int     i;
    int     hash_count;

    i = 0;
    hash_count = 0;
    l = ft_strlen(line);
    while (line[i])
            {
                if (line[i] != '.' && line[i] != '#')
                    ft_exit();
                if (line[i] == '#')
                    hash_count++;
                i++;
            }
            if ((l != 4) || (hash_count > 4))
                ft_exit();
            free(line);
            return (hash_count);
}

void    kostyl(char *line)
{
    if (ft_strlen(line))
        ft_exit1(line);
}
int     validity(int fd)
{
    int     str_count;
    int     hash_count;
    char    *line;

    fd = open("file", O_RDONLY);
    line = NULL;
    while (1)
    {
        str_count = 0;
        hash_count = 0;
        while (str_count++ < 4 && get_next_line(fd, &line) != 0)
            hash_count = hash_count + check_line_for_hash_n_dots(line);
        if (hash_count != 4)
            ft_exit1(line);
        if (get_next_line(fd, &line) == 1)
            kostyl(line);
        else
        {
            if (get_next_line(fd, &line) == 0)
                break;
        }
    }
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
void     filling_mas(int *buf, int i, int str_count)
{
        static int j = 0;
                        buf[j] = str_count;
                    buf[j + 1] = i;
                    j = j + 2;
}
int    *find_coord(int fd,int str_count,int i)
{
    int     j;
    int    *buf;
    char    *line;

    j = 0;
    buf = NULL;
        buf = (int*)malloc(sizeof(int) * 8);
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
return (buf);
}

t_tetris      *check_structure(int fd)
{
    int     k;
    t_tetris    *list;
    int        *buf;
    char        *line;
    int     str_count;
    int i;

    i = 0;
    k = 0;
    list = NULL;
    fd = open("file", O_RDONLY);
    while (1)
    {
        str_count = 0;
        buf = find_coord(fd,str_count,i);
        shift(buf);
        final_check(buf);
        list = ft_create_node_end(list,buf, k + 'A');
        k > 27 ? ft_exit()  :k++;
        if (!(get_next_line(fd, &line)))
            break;
        line = NULL;
    }
    return (list);
}

int     main(int argc, char **argv)
{
    t_tetris      *list;
    int             fd;

    fd = 0;
    if (argc != 2)
    {
        ft_putstr("usage: ./fillit source_file\n");
        exit(1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        ft_exit();
    validity(fd);
    list = check_structure(fd);
    solution(list);
    return (0);
}

/*int     main(void)
{
    t_tetris      *list;
    int             fd;

    fd = open("file", O_RDONLY);
    if (fd < 0)
        ft_exit();
    validity(fd);
    list = check_structure(fd);
    solution(list);
    return (0);
}*/
