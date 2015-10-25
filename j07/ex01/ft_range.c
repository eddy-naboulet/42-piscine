/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 13:23:43 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/25 13:24:00 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		cpt;
	int		*tab;

	cpt = 0;
	if (min >= max)
		return ((void*)0);
	tab = (int *)malloc(sizeof(int) * (max - min));
	if (tab == 0)
		return ((void*)0);
	while (min < max)
	{
		tab[cpt] = min;
		min++;
		cpt++;
	}
	return (tab);
}
