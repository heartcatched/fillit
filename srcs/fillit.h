#ifndef FILLIT_H
# define FILLIT_H
//#include "get_next_line.h"
#include "libft.h"

//fd2 = open("file2", O_WRONLY);
void	ft_exit(void);
int    min_x(int     *a);
int    min_y(int     *a);
void        shift(int   *a);
void    final_check(int *a);
int     me(int *a, int b[8]);
typedef struct  s_tetris
{
    int                 *tet_id;
    char                c;
    struct s_tetris     *next;
}                       t_tetris;
# define I (int[8]) {0,0,1,0,2,0,3,0}
# define I90 (int[8]) {0,0,0,1,0,2,0,3}
# define O (int[8]) {0,0,0,1,1,0,1,1}
# define L (int[8]) {0,0,1,0,2,0,2,1}
# define L90 (int[8]) {1,0,1,1,1,2,0,2}
# define L180 (int[8]) {0,0,0,1,1,1,2,1}
# define L270 (int[8]) {0,0,0,1,0,2,1,0}
# define J (int[8]) {0,1,1,1,2,1,2,0}
# define J90 (int[8]) {0,0,0,1,0,2,1,2}
# define J180 (int[8]) {0,0,0,1,1,0,2,0}
# define J270 (int[8]) {0,0,0,1,0,2,1,2}
# define T (int[8]) {0,0,0,1,0,2,1,1}
# define T90 (int[8]) {0,0,1,0,1,1,2,0}
# define T180 (int[8]) {0,1,1,0,1,1,1,2}
# define T270 (int[8]) {0,1,1,0,1,1,2,1}
# define S (int[8]) {0,1,0,2,1,0,1,1}
# define S90 (int[8]) {0,0,1,0,1,1,2,1}
# define Z (int[8]) {0,0,0,1,1,1,1,2}
# define Z90 (int[8]) {0,1,1,0,1,1,2,0}

int     max_x(int *a);
int     max_y(int *a);
int     collision_grid(int grid_size, int *tet_id);
int     collision_piece(char **grid, int *tet_id);
int     collision(char **grid, int grid_size, int *tet_id);
int     floor_of_sqrt(int n);
int     start_size(t_tetris *list);
void    solution(t_tetris *list);
int     exempt(char **grid, t_tetris *list, int grid_size);
int     insert_n_clear(int  *tet_id, t_tetris *list, char **grid, int grid_size);
void    insert(int *tet_id, char **grid, char c);
void    clear(int *tet_id, char **grid);
void    shift_yx(int *tet_id, int y, int x);
void    copy(int *a, int *b);
void    print(char **grid, int grid_size);
char	**create_grid(int grid_size);
void    free_grid(char **grid, int grid_size);
void	free_t_tetris(t_tetris *stack);
t_tetris	*ft_create_node_inbegin(t_tetris *list, int *a, char c);
t_tetris	*ft_create_node_end(t_tetris *list, int *a, char c);
void    ft_exit1(char *line);
int    check_line_for_hash_n_dots(char *line);
void    kostyl(char *line);
int     validity(int fd);
t_tetris    *ft_create_elem(int *content, t_tetris *next);
void     filling_mas(int *buf, int i, int str_count);
int    *find_coord(int fd,int str_count,int i);
t_tetris      *check_structure(int fd);
#endif
