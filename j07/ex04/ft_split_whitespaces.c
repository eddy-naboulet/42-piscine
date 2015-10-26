/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 13:25:22 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/26 16:44:51 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int			ft_words(char *str)
{
	unsigned int		cpt;
	unsigned int		wrd;

	cpt = 0;
	wrd = 0;
	while (str[cpt] != '\0')
	{
		if ((str[cpt] != ' ' && str[cpt] != '\t' &&
					str[cpt] != '\n') && (cpt == 0 || str[cpt - 1] == ' ' ||
						str[cpt - 1] == '\t' || str[cpt - 1] == '\n'))
			wrd++;
		cpt++;
	}
	return (wrd);
}

unsigned int			ft_cpt_w(char *str, unsigned int word)
{
	unsigned int		cpt;
	unsigned int		wrd;
	unsigned int		ltr;

	cpt = 0;
	wrd = 0;
	ltr = 0;
	while (str[cpt] != '\0')
	{
		if ((str[cpt] != ' ' && str[cpt] != '\t' &&
					str[cpt] != '\n') && (cpt == 0 || str[cpt - 1] == ' ' ||
						str[cpt - 1] == '\t' || str[cpt - 1] == '\n'))
			wrd++;
		if (wrd == word && str[cpt] != ' ' && str[cpt] != '\n' &&
				str[cpt] != '\t')
			ltr++;
		cpt++;
	}
	return (ltr);
}

void					aff(char **tab, char *str)
{
	unsigned int		cpt;
	unsigned int		wrd;
	unsigned int		cpt2;

	cpt = 0;
	cpt2 = 0;
	wrd = 0;
	while (str[cpt] != '\0')
	{
		if ((str[cpt] != ' ' && str[cpt] != '\t' && str[cpt] != '\n') &&
				(cpt == 0 || str[cpt - 1] == ' ' || str[cpt - 1] == '\t' ||
				str[cpt - 1] == '\n'))
		{
			if (wrd > 0)
				tab[wrd - 1][cpt2] = '\0';
			wrd++;
			cpt2 = 0;
		}
		if (str[cpt] != ' ' && str[cpt] != '\t' && str[cpt] != '\n')
		{
			tab[wrd - 1][cpt2] = str[cpt];
			cpt2++;
		}
		cpt++;
	}
}

char					**ft_split_whitespaces(char *str)
{
	unsigned int		wrd;
	char				**tab;
	unsigned int		word;

	wrd = ft_words(str);
	word = 1;
	tab = (char **)malloc(sizeof(char *) * (wrd + 1));
	while (word <= wrd)
	{
		tab[word - 1] = ((char *)malloc(sizeof(char) *
					(ft_cpt_w(str, word) + 1)));
		word++;
	}
	tab[word - 1] = 0;
	aff(tab, str);
	return (tab);
}
