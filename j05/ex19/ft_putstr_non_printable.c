/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 16:30:24 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/21 16:35:01 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

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

int		ft_verif(char *base)
{
	int		cpt;
	int		cpt2;

	cpt = 0;
	cpt2 = 1;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[cpt] != '\0')
	{
		while (base[cpt2 + cpt] != '\0')
		{
			if (base[cpt2 + cpt] == base[cpt])
				return (0);
			cpt2++;
		}
		if (base[cpt] == '-' || base[cpt] == '+' || base[cpt] <= 32 ||
				base[cpt] == 127)
			return (0);
		cpt2 = 1;
		cpt++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		cpt;

	cpt = 1;
	if (ft_verif(base) == 1)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr *= -1;
		}
		while (nbr / cpt > ft_strlen(base) - 1)
		{
			cpt *= ft_strlen(base);
		}
		while (cpt > 0)
		{
			ft_putchar(base[((nbr / cpt) % ft_strlen(base))]);
			cpt /= ft_strlen(base);
		}
	}
}

void	ft_putstr_non_printable(char *str)
{
	int		cpt;

	cpt = 0;
	while (str[cpt] != '\0')
	{
		if ((str[cpt] >= 0 && str[cpt] < 32) || str[cpt] == 127)
		{
			ft_putchar('\\');
			if (str[cpt] < 16)
				ft_putchar('0');
			ft_putnbr_base((int)str[cpt], "0123456789abcdef");
		}
		else
			ft_putchar(str[cpt]);
		cpt++;
	}
}
