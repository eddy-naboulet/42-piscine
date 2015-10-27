/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 12:00:58 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/27 12:24:55 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char*))
{
	int		cpt;

	cpt = 0;
	while (tab[cpt + 1] != 0)
	{
		if (cmp(tab[cpt], tab[cpt + 1]) > 0)
		{
			ft_swap(&(tab[cpt]), &(tab[cpt + 1]));
			cpt = 0;
		}
		else
			cpt++;
	}
}
