/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 13:36:14 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/25 12:39:33 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void	ft_show_tab(t_stock_par *par)
{
	int		cpt;
	int		cpt2;

	cpt = 0;
	cpt2 = 0;
	if (par != NULL)
	{
		while (par[cpt].str != 0)
		{
			ft_putstr(par[cpt].str);
			ft_putchar('\n');
			ft_putnbr(par[cpt].size_param);
			ft_putchar('\n');
			while (par[cpt].tab[cpt2] != 0)
			{
				ft_putstr(par[cpt].tab[cpt2]);
				ft_putchar('\n');
				cpt2++;
			}
			cpt2 = 0;
			cpt++;
		}
	}
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

void	ft_putnbr(int nb)
{
	int		cpt;

	cpt = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	while (nb / cpt > 9)
	{
		cpt *= 10;
	}
	while (cpt > 0)
	{
		ft_putchar(((nb / cpt) % 10) + '0');
		cpt /= 10;
	}
}
