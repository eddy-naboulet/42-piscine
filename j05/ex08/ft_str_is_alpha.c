/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 18:38:23 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/23 13:43:03 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
{
	int		cpt;

	cpt = 0;
	while (str[cpt] != '\0')
	{
		if ((str[cpt] < 'a' && str[cpt] > 'Z') || str[cpt] < 'A' ||
				str[cpt] > 'z')
			return (0);
		cpt++;
	}
	return (1);
}
