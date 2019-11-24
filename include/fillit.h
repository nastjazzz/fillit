/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhobert <hhobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:44:35 by hhobert           #+#    #+#             */
/*   Updated: 2019/11/24 19:14:50 by hhobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define READ_SIZE 546
# include "../libft/libft.h"
# include "fcntl.h"

typedef	struct			s_fillit
{
	int					fd;
	int					ret;
	char				*ln_t;
	int					lines;
	int					end_line;
}						t_fillit;

typedef	struct			s_tetrimino
{
	char				**tetro;
	char				**temp;
	char				**ready;
	int					h_t;
	int					w_h;
	char				letter;
	struct s_tetrimino	*next;
}						t_tetrimino;

typedef	struct			s_map
{
	int					size_m;
	char				**map;
}						t_map;

int						ft_valid_tetro(t_fillit *f);
t_tetrimino				*do_list(char *buf, int numb_tetri, t_tetrimino
		*tetr_current);
void					get_height(t_tetrimino *nw_elem);
void					get_width(t_tetrimino *nw_elem);
void					cut_tetr(t_tetrimino *nw_elem);
char					**set_mem(char **mem, int height, int width);
void					create_map(int size, t_map *m);
int						size_map(int nb);
int						recursia(t_map *m, t_tetrimino *t);
void					do_null(t_fillit *f);
void					print_error(const char *str);
void					ft_free(char **res);
void					ft_free_map(t_map *m);
void					ft_free_list(t_tetrimino *t);

#endif
