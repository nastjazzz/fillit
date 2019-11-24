/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhobert <hhobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:26:27 by hhobert           #+#    #+#             */
/*   Updated: 2019/11/21 18:23:11 by hhobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fillit.h"

void		get_width(t_tetrimino *nw_elem)
{
	int		i;
	int		j;
	int		count;
	int		min_w;
	int		max_w;

	count = 0;
	min_w = 0;
	max_w = 0;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (nw_elem->tetro[i][j] == '#' && count++ == 0)
				min_w = j;
			if (nw_elem->tetro[i][j] == '#' && count++ != 0)
				max_w = j;
			i++;
		}
		j++;
	}
	nw_elem->w_h = max_w - min_w + 1;
}

void		get_height(t_tetrimino *nw_elem)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < 4)
	{
		if (ft_strchr(nw_elem->tetro[i], '#'))
			count++;
		i++;
	}
	nw_elem->h_t = count;
}

int			part_tetr_col(t_tetrimino *nw, int k, int j)
{
	if (nw->temp[0][j] == '.' && nw->temp[(2 <= nw->h_t ? 1 : 0)][j] == '.' &&
	nw->temp[(3 <= nw->h_t ? 2 : 0)][j] == '.'
	&& nw->temp[(4 <= nw->h_t ? 3 : 0)][j] == '.')
	{
		j++;
		return (0);
	}
	else
	{
		nw->ready[0][k] = nw->temp[0][j];
		nw->ready[(2 <= nw->h_t ? 1 : 0)]
			[k] = nw->temp[(2 <= nw->h_t ? 1 : 0)][j];
		nw->ready[(3 <= nw->h_t ? 2 : 0)]
			[k] = nw->temp[(3 <= nw->h_t ? 2 : 0)][j];
		nw->ready[(4 <= nw->h_t ? 3 : 0)]
			[k] = nw->temp[(4 <= nw->h_t ? 3 : 0)][j];
		k++;
		return (1);
	}
	return (0);
}

void		cut_tetr_col(t_tetrimino *nw)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	nw->ready = set_mem(nw->ready, nw->h_t, nw->w_h);
	while (nw->temp[0][j])
	{
		if (part_tetr_col(nw, k, j))
			k++;
		j++;
	}
	i = 0;
	while (i < nw->h_t)
	{
		free(nw->temp[i]);
		nw->temp[i] = NULL;
		i++;
	}
	free(nw->temp);
	nw->temp = NULL;
}

void		cut_tetr(t_tetrimino *nw_elem)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(nw_elem->temp = (char **)malloc(sizeof(char *) * nw_elem->h_t)))
		print_error("error");
	while (i < 4)
	{
		if (ft_strncmp(nw_elem->tetro[i], "....", 4) < 0)
		{
			nw_elem->temp[j] = ft_strdup(nw_elem->tetro[i]);
			i++;
			j++;
		}
		else
			i++;
	}
	cut_tetr_col(nw_elem);
	ft_free(nw_elem->tetro);
}
