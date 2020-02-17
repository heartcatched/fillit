/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzoltan <wzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:07:37 by wzoltan           #+#    #+#             */
/*   Updated: 2020/02/15 17:26:55 by wzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

void					ft_exit(void);
int						min_x(int *a);
int						min_y(int *a);
void					shift(int *a);
void					final_check(int *a);
int						me(int *a, int b[8]);
typedef struct			s_tetris
{
	int					*tet_id;
	char				c;
	struct s_tetris		*next;
}						t_tetris;

int						max_x(int *a);
int						max_y(int *a);
int						collision_grid(int grid_size, int *tet_id);
int						collision_piece(char **grid, int *tet_id);
int						collision(char **grid, int grid_size, int *tet_id);
int						floor_of_sqrt(int n);
int						start_size(t_tetris *list);
void					solution(t_tetris *list);
int						exempt(char **grid, t_tetris *list, int grid_size);
int						insert_n_clear(int *t, t_tetris *l, char **g, int n);
void					insert(int *tet_id, char **grid, char c);
void					clear(int *tet_id, char **grid);
void					shift_yx(int *tet_id, int y, int x);
void					copy(int *a, int *b);
void					print(char **grid, int grid_size);
char					**create_grid(int grid_size);
void					free_grid(char **grid, int grid_size);
void					free_t_tetris(t_tetris *stack);
t_tetris				*ft_create_node_inbegin(t_tetris *list, int *a, char c);
t_tetris				*ft_create_node_end(t_tetris *list, int *a, char c);
void					ft_exit1(char *line);
int						check_line_for_hash_n_dots(char *line);
void					kostyl(char *line);
int						validity(int fd);
t_tetris				*ft_create_elem(int *content, t_tetris *next);
void					filling_mas(int *buf, int i, int str_count);
int						*find_coord(int fd, int str_count);
t_tetris				*check_structure(int fd);
int						correct_1(int *a);
int						correct_2(int *a);
void					free_t_tetris(t_tetris *stack);
void					free_list(t_tetris *list);
#endif
