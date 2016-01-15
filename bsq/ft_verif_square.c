/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afougere <afougere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 10:38:07 by afougere          #+#    #+#             */
/*   Updated: 2016/01/15 11:00:32 by afougere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		verif_header(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

int		verif_square(char **tab, t_def_map symbole)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (symbole.vide == symbole.obstacle || symbole.obstacle == symbole.plein
	|| symbole.vide == symbole.plein)
		return (0);
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] != symbole.vide && tab[i][j] != symbole.obstacle)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int		verif_place_square(char **tab, t_square place, t_def_map car)
{
	int i;
	int j;

	i = place.y;
	j = place.x;
	while (i < place.y + place.h)
	{
		while (j < place.x + place.w)
		{
			if (tab[i][j] == car.obstacle)
				return (0);
			j++;
		}
		i++;
		j = place.x;
	}
	return (1);
}

int		ft_error_bis(char **tab, t_def_map car)
{
	if ((verif_square(tab, car)) == 0)
		map_error();
	else
	{
		tab = resolve_square(tab, car);
		if (tab == NULL)
			map_error();
		else
			print_square(tab);
	}
	return (1);
}
