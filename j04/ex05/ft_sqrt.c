/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 21:28:51 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/15 21:29:31 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int		cpt;
	int		cpt2;

	cpt2 = nb / 2;
	cpt = 0;
	if (nb == 2 || nb == 3)
		return (0);
	if (nb <= 0)
		return (0);
	if (nb % 2 == 1)
		cpt = 1;
	while (cpt * cpt != nb && cpt <= cpt2)
	{
		cpt += 2;
	}
	if ((nb % cpt) == 0)
		return (cpt);
	return (0);
}
