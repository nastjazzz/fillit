/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logika.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhobert <hhobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:57:03 by hhobert           #+#    #+#             */
/*   Updated: 2019/11/21 18:02:08 by hhobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fillit.h"

void	create_map(int size, t_map *m)
{
	int	i;
	int	j;

	i = 0;
	if (!(m->map = (char **)malloc(sizeof(char *) * (size + 1))))
		print_error("error");
	while (i < size)
	{
		m->map[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			m->map[i][j] = '.';
			j++;
		}
		i++;
	}
	m->map[i] = 0;
	m->size_m = size;
}

int		part_put_tetr(t_tetrimino *t, t_map *m, int i, int j)
{
	int k;
	int p;

	k = 0;
	while (k < t->h_t)
	{
		p = 0;
		while (p < t->w_h)
		{
			if (m->map[i + k][j + p] != '.' && t->ready[k][p] != '.')
				return (0);
			p++;
		}
		k++;
	}
	return (1);
}

int		put_tetr(t_tetrimino *t, t_map *m, int i, int j)
{
	int	k;
	int	p;

	k = 0;
	if (!part_put_tetr(t, m, i, j))
		return (0);
	while (k < t->h_t)
	{
		p = 0;
		while (p < t->w_h)
		{
			if (m->map[i + k][j + p] == '.' && t->ready[k][p] == '#')
				m->map[i + k][j + p] = t->letter;
			p++;
		}
		k++;
	}
	return (1);
}

void	part_recursia(t_map *m, t_tetrimino *t)
{
	int k;

	k = 0;
	while (m->map[k])
	{
		ft_strset(m->map[k], t->letter, '.');
		k++;
	}
}

int		recursia(t_map *m, t_tetrimino *t)
{
	int	i;
	int	j;

	if (!t)
		return (1);
	i = 0;
	while (i <= m->size_m - t->h_t)
	{
		j = 0;
		while (j <= m->size_m - t->w_h)
		{
			if (put_tetr(t, m, i, j))
			{
				if (recursia(m, t->next))
					return (1);
				else
					part_recursia(m, t);
			}
			j++;
		}
		i++;
	}
	return (0);
}
