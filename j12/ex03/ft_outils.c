/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboul@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 21:05:18 by enaboule          #+#    #+#             */
/*   Updated: 2016/01/06 21:05:20 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		ft_strlen(char *str)
{
	int	cpt;

	cpt = 0;
	while (str[cpt] != '\0')
		cpt++;
	return (cpt);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_bs(int nbr, char *base)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= ft_strlen(base))
	{
		ft_bs(nbr / ft_strlen(base), base);
		ft_bs(nbr % ft_strlen(base), base);
	}
	else
		ft_putchar(base[nbr]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (nbr < 16)
		write(1, "0", 1);
	ft_bs(nbr, base);
}
