/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hxd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboul@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 21:05:08 by enaboule          #+#    #+#             */
/*   Updated: 2016/01/08 22:53:54 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		ft_hx(char *buf, int wr, int p)
{
	static unsigned int	cpt = 0;
	int					nbr;

	nbr = -1;
	ft_zero(cpt, p);
	ft_putnbr_base(cpt, "0123456789abcdef");
	write(1, "  ", p + 1);
	while (++nbr < wr)
	{
		ft_putnbr_base(buf[nbr], "0123456789abcdef");
		if ((nbr == 7 || nbr == 15) && p == 1)
			write(1, " ", 1);
		if (nbr + 1 < wr && p == 0)
			write(1, " ", 1);
		if (p == 1)
			write(1, " ", 1);
	}
	ft_space(nbr, p);
	while (nbr++ < 16)
		write(1, "   ", 3);
	cpt += 16;
	ft_sym(nbr, wr, buf, p);
	return (cpt);
}

void	ft_space(int nbr, int p)
{
	if (nbr < 16 && p == 1)
		write(1, " ", 1);
	if (nbr < 8 && p == 1)
		write(1, " ", 1);
}

int		cur_file(int argc, char **argv)
{
	int		op;
	int		cpt;
	int		op2;
	int		wr;
	char	buf[B];

	wr = B + 1;
	cpt = 1;
	op2 = open("filebis", O_TRUNC | O_RDWR | O_CREAT, 0777);
	while (cpt < argc)
	{
		if (!(ft_strlen(argv[cpt]) == 2 && argv[cpt][0] == '-' && argv[cpt][1]
		== 'C'))
		{
			op = open(argv[cpt], O_RDONLY);
			if (op == -1)
				ft_error(cpt, argc, argv[cpt]);
			else
				while ((wr = read(op, buf, B)) > 0)
					write(op2, buf, wr);
		}
		cpt++;
	}
	return (wr);
}

void	ft_dump(char *file, int p)
{
	int		filed;
	int		wr;
	char	buf[16];
	int		res;

	if (ft_strlen(file) != 0)
		filed = open(file, O_RDONLY);
	else
		filed = 0;
	while ((wr = read(filed, buf, 16)) > 0)
	{
		buf[wr] = '\0';
		res = ft_hx(buf, wr, p) - 16 + wr;
	}
	ft_zero(res, p);
	ft_putnbr_base(res, "0123456789abcdef");
	write(1, "\n", 1);
	if (filed != 0)
		close(filed);
}

int		main(int argc, char **argv)
{
	int	p;

	p = 0;
	if (argc > 1)
	{
		if (ft_strlen(argv[1]) == 2 && argv[1][0] == '-' && argv[1][1] == 'C')
			p = 1;
		if (cur_file(argc, argv) <= B)
			ft_dump(FILEBIS, p);
	}
	if (argc < 2 || (argc == 2 && argv[1][0] == '-' && argv[1][1]
	== 'C' && argv[1][2] == '\0'))
		ft_dump("", p);
	return (0);
}
