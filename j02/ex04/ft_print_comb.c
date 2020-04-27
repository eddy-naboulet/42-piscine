/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 21:31:20 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/14 21:31:48 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_aff(char centaine, char dizaine, char unite)
{
	if (unite > dizaine && dizaine > centaine)
	{
		ft_putchar(centaine);
		ft_putchar(dizaine);
		ft_putchar(unite);
		if (centaine < '7')
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

void	ft_print_comb(void)
{
	char	centaine;
	char	dizaine;
	char	unite;

	centaine = '0';
	dizaine = '0';
	unite = '0';
	while (centaine <= '9')
	{
		while (dizaine <= '9')
		{
			while (unite <= '9')
			{
				ft_aff(centaine, dizaine, unite);
				unite++;
			}
			dizaine++;
			unite = '0';
		}
		centaine++;
		dizaine = '0';
	}
}
