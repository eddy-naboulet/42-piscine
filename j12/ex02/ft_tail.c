/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboul@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:11:01 by enaboule          #+#    #+#             */
/*   Updated: 2015/11/26 16:11:45 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int		ft_strlen(char *str)
{
	int		cpt;

	cpt = 0;
	while (str[cpt] != '\0')
		cpt++;
	return (cpt);
}

void	ft_fleche(char *file)
{
	static int	cpt = 0;

	if (cpt > 0)
		write(1, "\n", 1);
	write(1, "==> ", 4);
	write(1, file, ft_strlen(file));
	write(1, " <==\n", 5);
	cpt++;
}

void	ft_tail(char *file, int nb, int argc)
{
	int		op;
	char	*bf1;
	char	*bf2;

	bf1 = (char *)malloc(sizeof(char) * (nb + 1));
	bf2 = (char *)malloc(sizeof(char) * (nb + 1));
	op = open(file, O_RDONLY);
	if (op == -1)
	{
		write(2, "ft_tail : cannot open '", 22);
		write(2, file, ft_strlen(file));
		write(2, "' for reading: No such file or directory\n", 41);
	}
	else
	{
		if (argc > 4)
			ft_fleche(file);
		ft_write(op, bf1, bf2, nb);
	}
	close(op);
	free(bf1);
	free(bf2);
}

void	ft_write(int op, char *bf1, char *bf2, int nb)
{
	int		wr;
	int		wr2;
	int		cpt;

	while ((wr = read(op, bf1, nb)) > 0)
	{
		if (wr < nb)
		{
			write(1, bf2 + wr, wr2 - wr);
			write(1, bf1, wr);
		}
		wr2 = wr;
		cpt = 0;
		while (bf1[cpt] != '\0')
		{
			bf2[cpt] = bf1[cpt];
			cpt++;
		}
	}
	if (wr2 == nb)
		write(1, bf2, wr2);
}

int		main(int argc, char **argv)
{
	int		cpt;
	int		nb;

	cpt = 1;
	while (cpt < argc)
	{
		if (cpt + 1 < argc && ft_strlen(argv[cpt]) >= 2 && argv[cpt][0] ==
		'-' && argv[cpt][1] == 'c')
			nb = ft_atoi(argv[cpt + 1]);
		cpt++;
	}
	cpt = 1;
	while (cpt < argc)
	{
		if (argv[cpt][0] == '-' && argv[cpt][1] == '\0')
			argc = 0;
		else if (((ft_strlen(argv[cpt]) == 2 && argv[cpt][0] != '-' &&
			argv[cpt][1] != 'c') || ft_strlen(argv[cpt]) != 2) &&
			((ft_strlen(argv[cpt - 1]) == 2 && argv[cpt - 1][0] != '-' &&
			argv[cpt - 1][1] != 'c') || ft_strlen(argv[cpt - 1]) != 2))
			ft_tail(argv[cpt], nb, argc);
		cpt++;
	}
	return (0);
}
