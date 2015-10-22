/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 13:23:20 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/22 09:26:35 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

struct s_stock_par		*ft_param_to_tab(int ac, char **av)
{
	struct s_stock_par	*tab;
	int					cpt;

	tab = (t_stock_par *)malloc(sizeof(t_stock_par) * (ac + 1));
	cpt = 0;
	while (cpt < ac)
	{
		tab[cpt].size_param = ft_strlen(av[cpt]);
		tab[cpt].str = av[cpt];
		tab[cpt].copy = ft_strdup(av[cpt]);
		tab[cpt].tab = ft_split_whitespaces(av[cpt]);
		cpt++;
	}
	tab[cpt].str = 0;
	return (&(tab[0]));
}

int						ft_strlen(char *str)
{
	int		cpt;

	cpt = 0;
	while (str[cpt] != '\0')
	{
		cpt++;
	}
	return (cpt);
}

char					*ft_strdup(char *src)
{
	int		cpt;
	char	*dup;

	cpt = 0;
	while (src[cpt] != '\0')
	{
		cpt++;
	}
	dup = (char *)malloc(sizeof(char) * (cpt + 1));
	if (dup == NULL)
		return (NULL);
	while (cpt >= 0)
	{
		dup[cpt] = src[cpt];
		cpt--;
	}
	return (dup);
}
