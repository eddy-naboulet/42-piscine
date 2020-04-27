/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 21:53:06 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/22 22:21:26 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_rot42(char *str)
{
	int		cpt;

	cpt = 0;
	if (str == (void*)0)
		return ((void*)0);
	while (str[cpt] != '\0')
	{
		if (str[cpt] <= 122 && str[cpt] >= 97)
			str[cpt] = (str[cpt] + 42 - 97) % 26 + 97;
		else if (str[cpt] <= 90 && str[cpt] >= 65)
			str[cpt] = (str[cpt] + 42 - 65) % 26 + 65;
		cpt++;
	}
	return (str);
}
