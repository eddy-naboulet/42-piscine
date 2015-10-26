/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 17:17:14 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/26 17:19:48 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		cpt;

	cpt = 0;
	while (str[cpt] != '\0')
		cpt++;
	return (cpt);
}

int		ft_verif(char wrd, char *base)
{
	int		cpt;

	cpt = 0;
	while (base[cpt] != '\0')
	{
		if (base[cpt] == wrd)
			return (cpt);
		cpt++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int		cpt;
	int		sb;

	cpt = 0;
	sb = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-')
	{
		sb = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_verif(*str, base) != -1)
	{
		cpt = (cpt * ft_strlen(base)) + ft_verif(*str, base);
		str++;
	}
	return (cpt * sb);
}

void	ft_ligne(int *cpt, int *cpt2, char *base_to, int cpt3)
{
	while (cpt3 / *cpt > ft_strlen(base_to) - 1)
	{
		*cpt *= ft_strlen(base_to);
		(*cpt2)++;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		cpt;
	int		cpt2;
	char	*res;
	int		cpt3;

	cpt2 = 1;
	cpt3 = 0;
	cpt = ft_atoi_base(nbr, base_from);
	ft_ligne(&cpt2, &cpt3, base_to, cpt);
	res = (char*)malloc(sizeof(char) * (cpt3 + ((cpt < 0) ? 1 : 0)));
	cpt3 = (cpt < 0) ? 1 : 0;
	res[0] = '-';
	cpt2 = (cpt < 0) ? cpt2 * ft_strlen(base_to) : cpt2;
	cpt = (cpt < 0) ? -cpt : cpt;
	while (cpt2 >= 1)
	{
		res[cpt3] = base_to[(cpt / cpt2) % ft_strlen(base_to)];
		cpt2 /= ft_strlen(base_to);
		cpt3++;
	}
	res[cpt3] = '\0';
	return (res);
}
