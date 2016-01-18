/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afougere <afougere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 10:05:58 by afougere          #+#    #+#             */
/*   Updated: 2016/01/18 14:26:05 by afougere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_def_map	read_header(char *file, int *fd)
{
	int			rec;
	int			i;
	char		buf[BUF_SIZE];
	t_def_map	car;

	i = -1;
	car.line_size = count_car(file);
	if ((*fd = open(file, O_RDONLY)) == -1)
	{
		car.line_size = -1;
		return (car);
	}
	while (i == -1 || buf[i] != '\n')
		rec = read(*fd, &buf[++i], 1);
	buf[i] = '\0';
	car.plein = buf[--i];
	car.obstacle = buf[--i];
	car.vide = buf[--i];
	car.map_size = (char *)malloc(sizeof(char) * (i + 1));
	car.map_size[i] = '\0';
	while (i-- > 0)
		car.map_size[i] = buf[i];
	if (verif_header(car.map_size) == 0 && (car.line_size = -1) == -1)
		return (car);
	return (car);
}

char		**read_square(char *file, t_def_map *car)
{
	char	**tab;
	int		fd;
	char	buf;

	if (((*car).line_size = count_car(file)) == -1)
		return (NULL);
	*car = read_header(file, &fd);
	(*car).size = ft_atoi((*car).map_size);
	(*car).line_size /= (*car).size;
	tab = (char **)malloc(sizeof(char *) * ((*car).size + 1));
	if (tab == NULL)
		return (NULL);
	tab[(*car).size] = NULL;
	if ((tab = read_square_bis(fd, *car, tab)) == NULL)
		return (NULL);
	if (read(fd, &buf, 1) > 0)
		return (NULL);
	return (tab);
}

char		**read_square_bis(int fd, t_def_map car, char **tab)
{
	char	buf;
	int		i;

	i = 0;
	while (i < car.size)
	{
		tab[i] = (char *)malloc(sizeof(char) * (car.line_size + 1));
		tab[i][car.line_size] = '\0';
		if (read(fd, tab[i], car.line_size) <= 0)
			return (NULL);
		read(fd, &buf, 1);
		i++;
	}
	return (tab);
}
