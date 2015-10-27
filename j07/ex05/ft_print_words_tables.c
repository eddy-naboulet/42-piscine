/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 19:40:18 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/27 11:41:10 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_words_tables(char **tab)
{
	unsigned int		cpt;
	unsigned int		cpt2;

	cpt = 0;
	cpt2 = 0;
	while (tab[cpt] != 0)
	{
		while (tab[cpt][cpt2] != '\0')
		{
			ft_putchar(tab[cpt][cpt2]);
			cpt2++;
		}
		ft_putchar('\n');
		cpt++;
		cpt2 = 0;
	}
}
