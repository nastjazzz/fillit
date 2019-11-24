/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhobert <hhobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:32:57 by hhobert           #+#    #+#             */
/*   Updated: 2019/11/24 18:47:58 by hhobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fillit.h"

int		part_two_check_connection(t_fillit *f, int i, int end_square)
{
	int	k;

	k = 0;
	if (i + end_square + 1 <= 545 && f->ln_t[i + end_square + 1] == '#')
		k++;
	if (i + end_square - 1 >= 0 && f->ln_t[i + end_square - 1] == '#')
		k++;
	if (end_square <= 15)
		if (i + end_square + 5 <= 545
				&& f->ln_t[i + end_square + 5] == '#')
			k++;
	if (end_square >= 5)
		if (i + end_square - 5 >= 0 && f->ln_t[i + end_square - 5] == '#')
			k++;
	return (k);
}

int		part_check_connection(t_fillit *f, int i, int hash, int connection)
{
	int end_square;

	end_square = 0;
	while (end_square <= 20)
	{
		if (f->ln_t[i + end_square] == '#')
		{
			hash++;
			connection += part_two_check_connection(f, i, end_square);
		}
		end_square++;
	}
	if (hash != 4 || (connection != 6 && connection != 8))
		return (0);
	return (connection);
}

int		check_connection(t_fillit *f)
{
	int	i;
	int	connection;
	int	hash;

	i = 0;
	hash = 0;
	connection = 0;
	while (i < (int)ft_strlen(f->ln_t) && f->ln_t[i])
	{
		if (i % 21 == 0 && i != 0)
		{
			connection = 0;
			hash = 0;
		}
		if (!(connection = part_check_connection(f, i, hash, connection)))
		{
			return (0);
		}
		i += 21;
	}
	return (1);
}

int		part_valid_tetro(t_fillit *f)
{
	int	i;

	i = 0;
	do_null(f);
	while (f->ln_t[i])
	{
		f->end_line++;
		if (f->ln_t[i] != '#' && f->ln_t[i] != '.' && f->ln_t[i] != '\n')
			return (0);
		if (i % 21 == 0)
		{
			if (i > 0 && f->ln_t[i - 1] != '\n')
				return (0);
			f->end_line = 0;
		}
		if (f->end_line == 5)
		{
			if (f->ln_t[i - 1] != '\n')
				return (0);
			f->end_line = 0;
		}
		if (f->ln_t[i++] == '\n')
			f->lines++;
	}
	return (f->lines);
}

int		ft_valid_tetro(t_fillit *f)
{
	int	lines;

	if (!(lines = part_valid_tetro(f)))
		return (0);
	if (check_connection(f) == 0)
		return (0);
	if ((lines + 1) % 5 == 0)
		return (1);
	return (0);
}
