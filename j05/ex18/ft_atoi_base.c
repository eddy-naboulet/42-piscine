/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 16:29:57 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/23 19:22:42 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_base(char wrd, char *base)
{
	int		cpt;

	cpt = 0;
	while (base[cpt] != '\0')
	{
		if (wrd == base[cpt])
			return (cpt);
		cpt++;
	}
	return (-1);
}

int		ft_cpt(char *base)
{
	int		cpt;

	cpt = 0;
	while (*base != '\0')
	{
		cpt++;
		base++;
	}
	return (cpt);
}

int		ft_verif(char *base)
{
	int		cpt;

	if (*base == '\0' || *(base + 1) == '\0')
		return (0);
	while (*base != '\0')
	{
		cpt = 1;
		while (base[cpt] != '\0')
		{
			if (*base == base[cpt] ||
					(base[cpt] == '-' || base[cpt] == '+'))
				return (0);
			cpt++;
		}
		base++;
	}
	return (1);
}

int		ft_atoi_base(char *str, char *base)
{
	int		nb;
	int		cpt;
	int		ng;

	ng = 1;
	if (!ft_verif(base))
		return (0);
	if (*str == '-' || *str == '+')
	{
		ng = (*str == '-') ? -1 : 1;
		str++;
	}
	cpt = ft_cpt(base);
	nb = 0;
	while (*str != '\0')
	{
		nb *= cpt;
		if (ft_base(*str, base) == -1)
			return (0);
		nb += (ft_base(*str, base));
		str++;
	}
	return (nb * ng);
}
