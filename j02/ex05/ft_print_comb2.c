/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 21:32:49 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/14 21:32:52 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_aff(char millier, char centaine, char dizaine, char unite)
{
	if ((dizaine * 10 + unite) > (millier * 10 + centaine))
	{
		ft_putchar(millier);
		ft_putchar(centaine);
		ft_putchar(' ');
		ft_putchar(dizaine);
		ft_putchar(unite);
		if ((millier * 10 + centaine) < ('9' * 10 + '8'))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

void	ft_print_comb2(void)
{
	char	millier;
	char	centaine;
	char	dizaine;
	char	unite;

	millier = '0';
	while (millier <= '9')
	{
		centaine = '0';
		while (centaine <= '9')
		{
			dizaine = '0';
			while (dizaine <= '9')
			{
				unite = '0' - 1;
				while (++unite <= '9')
					ft_aff(millier, centaine, dizaine, unite);
				dizaine++;
			}
			centaine++;
		}
		millier++;
	}
}
