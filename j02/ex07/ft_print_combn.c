/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 21:34:09 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/14 21:35:10 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_test(int cpt)
{
	if (cpt == 0)
		return (0);
	while (cpt / 10 > 0)
	{
		if (cpt % 10 > cpt / 10 % 10)
		{
			cpt /= 10;
		}
		else
			return (0);
	}
	return (1);
}

void	ft_carac(int cpt, int max)
{
	if (cpt < max)
	{
		ft_putchar(' ');
		ft_putchar(',');
	}
}

void	ft_putnbr(int nb, int n)
{
	int		cpt;

	cpt = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	while (nb / cpt > 9)
	{
		cpt *= 10;
		n--;
	}
	while (n > 1)
	{
		ft_putchar('0');
		n--;
	}
	while (cpt >= 1)
	{
		ft_putchar(((nb / cpt) % 10) + '0');
		cpt /= 10;
	}
}

void	ft_print_combn(int n)
{
	int		cpt;
	int		max;
	int		stk;

	cpt = 0;
	max = 1;
	stk = n + 1;
	if (n > 0 && n < 10)
	{
		while (--stk > 0)
			max *= 10;
		while (cpt < max && cpt <= 123456789)
		{
			if (ft_test(cpt))
			{
				ft_putnbr(cpt, n);
				ft_carac(cpt, max - (n * (max / 10)));
			}
			if (cpt == 23456789)
				cpt = 123456788;
			cpt++;
		}
	}
}
