/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 12:00:14 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/27 12:32:42 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort_wordtab(char **tab)
{
	int		cpt;

	cpt = 0;
	while (tab[cpt + 1] != 0)
	{
		if (ft_strcmp(tab[cpt], tab[cpt + 1]) > 0)
		{
			ft_swap(&(tab[cpt]), &(tab[cpt + 1]));
			cpt = 0;
		}
		else
			cpt++;
	}
}
