/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 11:56:10 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/27 11:59:00 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_add(int a, int b);
int		ft_multi(int a, int b);
int		ft_sou(int a, int b);
int		ft_div(int a, int b);
int		ft_mod(int a, int b);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);
void	ft_putchar(char c);

int		ft_sb(char sb, char op[5])
{
	int		cpt;

	cpt = 0;
	while (cpt < 5)
	{
		if (op[cpt] == sb)
			return (cpt);
		cpt++;
	}
	return (0);
}

void	ft_do_op(char *nb, char sb, char *nb2)
{
	char	tab[5];
	int		(*op[5])(int, int);

	tab[0] = '+';
	tab[1] = '*';
	tab[2] = '-';
	tab[3] = '/';
	tab[4] = '%';
	op[0] = &ft_add;
	op[1] = &ft_multi;
	op[2] = &ft_sou;
	op[3] = &ft_div;
	op[4] = &ft_mod;
	ft_putnbr(op[ft_sb(sb, tab)](ft_atoi(nb), ft_atoi(nb2)));
}

void	ft_putnbr(int nb)
{
	unsigned int	cpt;

	cpt = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	while (nb / cpt > 9)
	{
		cpt *= 10;
	}
	while (cpt >= 1)
	{
		ft_putchar(((nb / cpt) % 10) + '0');
		cpt /= 10;
	}
}
