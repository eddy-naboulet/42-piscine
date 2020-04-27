/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 11:56:30 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/27 12:47:42 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_do_op(char *nb, char sb, char *nb2);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_putstr(char *str);
void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	if (argc == 4)
	{
		if ((argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != '*' &&
					argv[2][0] != '/' && argv[2][0] != '%') ||
				ft_strlen(argv[2]) != 1)
		{
			ft_putstr("0\n");
			return (0);
		}
		if (argv[2][0] == '/' && ft_atoi(argv[3]) == 0)
		{
			ft_putstr("Stop : division by zero\n");
			return (0);
		}
		if (argv[2][0] == '%' && ft_atoi(argv[3]) == 0)
		{
			ft_putstr("Stop : modulo by zero\n");
			return (0);
		}
		ft_do_op(argv[1], argv[2][0], argv[3]);
		ft_putchar('\n');
	}
}

int		ft_strlen(char *str)
{
	int		cpt;

	cpt = 0;
	while (str[cpt] != '\0')
	{
		cpt++;
	}
	return (cpt);
}

int		ft_atoi(char *str)
{
	int		cpt;
	int		sgn;

	cpt = 0;
	sgn = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
	{
		cpt++;
	}
	if (*str == '-')
	{
		sgn = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		cpt = cpt * 10 + *str - '0';
		str++;
	}
	return (cpt * sgn);
}

void	ft_putstr(char *str)
{
	int		cpt;

	cpt = 0;
	while (str[cpt] != '\0')
	{
		ft_putchar(str[cpt]);
		cpt++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
