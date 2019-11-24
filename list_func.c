/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhobert <hhobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:05:23 by hhobert           #+#    #+#             */
/*   Updated: 2019/11/21 18:00:35 by hhobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fillit.h"

char			**set_mem(char **mem, int height, int width)
{
	int			i;

	i = 0;
	if (!(mem = (char **)malloc((sizeof(char *)) * (height + 1))))
		print_error("Error_Malloc");
	else
	{
		while (i < height)
		{
			mem[i] = ft_strnew(width);
			i++;
		}
		mem[i] = NULL;
	}
	return (mem);
}

void			get_params(t_tetrimino *nw_elem)
{
	get_height(nw_elem);
	get_width(nw_elem);
}

t_tetrimino		*record_in_tetro(t_tetrimino *nw_elem, char *buf)
{
	int			row;
	int			col;
	int			i;

	i = 0;
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			nw_elem->tetro[row][col] = buf[i];
			i++;
			col++;
		}
		nw_elem->tetro[row][col] = '\0';
		i++;
		row++;
	}
	get_params(nw_elem);
	cut_tetr(nw_elem);
	i = 0;
	return (nw_elem);
}

t_tetrimino		*add_new_elem(char *buf)
{
	t_tetrimino	*nw_elem;
	int			i;

	i = 0;
	if (!(nw_elem = (t_tetrimino *)malloc(sizeof(t_tetrimino))))
		return (NULL);
	if (!(nw_elem->tetro = (char **)malloc(sizeof(char *) * 5)))
		return (NULL);
	while (i < 4)
	{
		if (!(nw_elem->tetro[i] = ft_strnew(4)))
			return (NULL);
		i++;
	}
	nw_elem->tetro[i] = NULL;
	return (record_in_tetro(nw_elem, buf));
}

t_tetrimino		*do_list(char *buf, int numb_tetri, t_tetrimino *tetr_current)
{
	t_tetrimino	*tmp;
	int			i;
	int			cur;

	tmp = add_new_elem(buf);
	tetr_current = tmp;
	tmp->letter = 'A';
	i = 1;
	cur = 21;
	while (i < numb_tetri)
	{
		if (!(tmp->next = add_new_elem(buf + cur)))
			print_error("Error_add_new_elem");
		tmp = tmp->next;
		tmp->letter = 'A' + i++;
		cur += 21;
	}
	tmp->next = NULL;
	return (tetr_current);
}
