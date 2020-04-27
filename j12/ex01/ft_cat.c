/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboul@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:09:06 by enaboule          #+#    #+#             */
/*   Updated: 2015/11/26 16:54:21 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int		ft_strlen(char *str)
{
	int		cpt;

	cpt = 0;
	while (str[cpt] != '\0')
		cpt++;
	return (cpt);
}

void	ft_cat(char *file)
{
	int		op;
	int		wr;
	char	buf[30720];

	op = open(file, O_RDONLY);
	if (op == -1)
	{
		write(2, "cat: ", 5);
		write(2, file, ft_strlen(file));
		write(2, ": No such file or directory\n", 28);
	}
	else
	{
		while ((wr = read(op, buf, 30720)) > 0)
			write(1, buf, wr);
	}
	close(op);
}

int		main(int argc, char **argv)
{
	int		cpt;
	int		wr;
	char	buf[30720];

	cpt = 1;
	while (cpt < argc)
	{
		if (argv[cpt][0] == '-' && argv[cpt][1] == '\0')
			argc = 0;
		else
			ft_cat(argv[cpt]);
		cpt++;
	}
	if (argc < 2 || (argc > 2 && argv[1][0] == '-' && argv[cpt][1]
		== '\0'))
	{
		while ((wr = read(0, buf, 30720) != 0))
			write(1, buf, wr);
	}
	return (0);
}
