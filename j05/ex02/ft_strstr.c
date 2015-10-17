/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 18:35:20 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/17 19:54:22 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		cpt;
	int		cpt2;

	cpt = 0;
	cpt2 = 0;
	if (to_find[cpt2] == '\0')
		return (str);
	while (str[cpt] != '\0')
	{
		while (to_find[cpt2] == str[cpt + cpt2])
		{
			cpt2++;
			if (to_find[cpt2] == '\0')
				return (&str[cpt]);
		}
		cpt++;
		cpt2 = 0;
	}
	return ((void*)0);
}
