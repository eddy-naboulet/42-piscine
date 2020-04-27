/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 11:55:51 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/27 11:55:58 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		cpt;
	int		croi;
	int		decroi;

	cpt = 0;
	croi = 1;
	decroi = 1;
	while (cpt < length - 1)
	{
		if (f(tab[cpt], tab[cpt + 1]) > 0)
			croi = 0;
		cpt++;
	}
	cpt = 0;
	while (cpt < length - 1)
	{
		if (f(tab[cpt], tab[cpt + 1]) < 0)
			decroi = 0;
		cpt++;
	}
	if (croi == 1 || decroi == 1)
		return (1);
	return (0);
}
