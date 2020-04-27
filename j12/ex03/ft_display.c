/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboul@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 21:04:56 by enaboule          #+#    #+#             */
/*   Updated: 2016/01/08 22:55:20 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_zero(unsigned int cpt, int p)
{
	int	nbr;

	nbr = 0;
	if (cpt <= 0)
		nbr = 6;
	else if (cpt < 16)
		nbr = 7;
	else if (cpt < 256)
		nbr = 6;
	else if (cpt < 4096)
		nbr = 5;
	else if (cpt < 65536)
		nbr = 4;
	else if (cpt < 1048576)
		nbr = 3;
	else if (cpt < 16777216)
		nbr = 2;
	else if (cpt < 268435456)
		nbr = 1;
	while (nbr > 0 + (p + 1) % 2)
	{
		write(1, "0", 1);
		nbr--;
	}
}

void	ft_sym(int nb, int rc, char *buf, int p)
{
	nb = 0;
	if (p > 0)
	{
		write(1, "|", 1);
		while (nb < rc)
		{
			if (buf[nb] == '\n' || buf[nb] == '\t')
				write(1, ".", 1);
			else
				write(1, &buf[nb], 1);
			nb++;
		}
		write(1, "|", 1);
	}
	write(1, "\n", 1);
}

void	ft_error(int cpt, int argc, char *file)
{
	write(2, "hexdump: ", 9);
	write(2, file, ft_strlen(file));
	write(2, ": No such file or directory\n", 28);
	if (cpt == argc - 1)
	{
		write(2, "hexdump: ", 9);
		write(2, file, ft_strlen(file));
		write(2, ": Bad file descriptor\n", 22);
	}
}
