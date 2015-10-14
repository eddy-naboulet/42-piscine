/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 21:33:40 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/14 21:33:44 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

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
