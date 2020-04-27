/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_square.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afougere <afougere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 10:36:04 by afougere          #+#    #+#             */
/*   Updated: 2016/01/18 14:31:21 by afougere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			count_car(char *file)
{
	int		fd;
	int		haha;
	char	buf[BUF_SIZE];
	int		car;
	int		i;

	i = -1;
	car = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	buf[0] = '\0';
	while (buf[0] != '\n')
		read(fd, buf, 1);
	while ((haha = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[haha] = '\0';
		while (buf[++i] != '\0')
		{
			if (buf[i] == '\n')
				haha--;
		}
		car += haha;
	}
	close(fd);
	return (car);
}

char		**split_square(char **tab, t_square place, t_def_map car)
{
	int i;
	int j;

	i = place.y;
	j = place.x;
	while (i < place.y + place.h)
	{
		while (j < place.x + place.w)
		{
			tab[i][j] = car.plein;
			j++;
		}
		i++;
		j = place.x;
	}
	return (tab);
}

char		**resolve_square(char **tab, t_def_map car)
{
	t_square place;

	place.x = 0;
	place.y = 0;
	place.w = (car.line_size < car.size) ? car.line_size : car.size;
	place.h = (car.line_size < car.size) ? car.line_size : car.size;
	while (place.w > 0)
	{
		while (place.y <= car.size - place.w)
		{
			while (place.x <= car.line_size - place.w)
			{
				if (verif_place_square(tab, place, car) == 1)
					return (split_square(tab, place, car));
				place.x++;
			}
			place.y++;
			place.x = 0;
		}
		place.w--;
		place.h--;
		place.y = 0;
	}
	return (tab);
}

void		print_square(char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			write(1, &tab[i][j], 1);
			j++;
		}
		i++;
		j = 0;
		write(1, "\n", 1);
	}
}

int			main(int argc, char **argv)
{
	t_def_map	car;
	char		**tab;
	char		buf[BUF_SIZE];
	int			fd;
	int			i;

	if (argc <= 1)
	{
		fd = open("bsq.tmp", O_CREAT | O_TRUNC | O_RDWR, 0777);
		while ((i = read(0, buf, BUF_SIZE)) > 0)
			write(fd, buf, i);
		close(fd);
		if ((tab = read_square("bsq.tmp", &car)) == NULL)
			map_error();
		else
			ft_error_bis(tab, car);
	}
	i = 0;
	while (++i < argc)
		if ((tab = read_square(argv[i], &car)) == NULL || ft_error_bis(tab, car)
		== -1)
			map_error();
	return (0);
}
