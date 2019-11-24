/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhobert <hhobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:21:16 by hhobert           #+#    #+#             */
/*   Updated: 2019/11/24 18:48:25 by hhobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fillit.h"

int		size_map(int nb)
{
	while (!ft_sqrt(nb))
	{
		nb++;
	}
	return (ft_sqrt(nb));
}

int		ft_numb_tetriminos(char *buf)
{
	int i;
	int number;

	i = 0;
	number = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '#')
			number++;
		i++;
	}
	if ((number % 4) != 0)
		return (0);
	number /= 4;
	return (number);
}

void	read_file(t_fillit *f, char *file, t_map *m)
{
	char		buf[READ_SIZE + 1];
	int			numb_tetri;
	t_tetrimino	*tetr_current;

	tetr_current = NULL;
	if (!(f->fd = open(file, O_RDONLY, S_IREAD)))
		print_error("error");
	if (!(f->ret = read(f->fd, buf, READ_SIZE)))
		print_error("error");
	if (f->ret < 20 || f->ret > 545)
		print_error("error");
	buf[f->ret] = '\0';
	f->ln_t = ft_strdup(buf);
	numb_tetri = ft_numb_tetriminos(buf);
	close(f->fd);
	if (!ft_valid_tetro(f))
		print_error("error");
	tetr_current = do_list(f->ln_t, numb_tetri, tetr_current);
	create_map(size_map(numb_tetri * 4), m);
	while (!(recursia(m, tetr_current)))
	{
		ft_free_map(m);
		create_map(m->size_m + 1, m);
	}
	ft_free_list(tetr_current);
}

int		main(int argc, char **argv)
{
	t_fillit	f;
	t_map		m;
	int			i;

	i = 0;
	if (argc < 2 || argc > 2)
		print_error("\t usage: ./fillit [1 source_file]");
	else
	{
		read_file(&f, argv[1], &m);
		while (m.map[i])
		{
			ft_putendl(m.map[i]);
			i++;
		}
		ft_free_map(&m);
		free(f.ln_t);
		f.ln_t = NULL;
	}
	return (0);
}
