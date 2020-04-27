/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboul@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:08:04 by enaboule          #+#    #+#             */
/*   Updated: 2015/11/26 16:52:07 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_display_file(char *file)
{
	int		op;
	int		wr;
	char	buf[201];

	op = open(file, O_RDONLY);
	if (op == -1)
		write(2, "File name missing\n", 19);
	else
	{
		while ((wr = read(op, buf, 200)) > 0)
			write(1, buf, wr);
	}
}

int		main(int argc, char **argv)
{
	if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else if (argc < 2)
		write(2, "File name missing.\n", 19);
	else
		ft_display_file(argv[1]);
	return (0);
}
