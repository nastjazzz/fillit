/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhobert <hhobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:06:55 by hhobert           #+#    #+#             */
/*   Updated: 2019/11/21 18:24:03 by hhobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fillit.h"

void			ft_free(char **res)
{
	int			i;

	i = 0;
	while (res[i] != '\0')
	{
		free(res[i]);
		res[i] = NULL;
		i++;
	}
	free(res);
	res = NULL;
}

void			do_null(t_fillit *f)
{
	f->lines = 0;
	f->end_line = 0;
}

void			print_error(const char *str)
{
	ft_putendl(str);
	exit(-1);
}

void			ft_free_map(t_map *m)
{
	int			i;

	i = 0;
	while (i < m->size_m)
	{
		free(m->map[i]);
		m->map[i] = NULL;
		i++;
	}
	free(m->map);
	m->map = NULL;
}

void			ft_free_list(t_tetrimino *t)
{
	int			i;
	t_tetrimino	*now;

	while (t != 0)
	{
		i = 0;
		while (i < t->h_t)
		{
			free(t->ready[i]);
			t->ready[i] = NULL;
			i++;
		}
		free(t->ready);
		t->ready = NULL;
		now = t->next;
		free(t);
		t = now;
	}
}
