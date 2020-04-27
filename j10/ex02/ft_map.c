/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 11:54:16 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/27 12:25:50 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		cpt;
	int		*res;

	res = (int*)malloc(sizeof(int) * length);
	cpt = 0;
	while (cpt < length)
	{
		res[cpt] = f(tab[cpt]);
		cpt++;
	}
	return (res);
}
