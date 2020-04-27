/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 09:10:01 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/21 16:29:23 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_num(char str)
{
	if (str < '0' || str > '9')
		return (0);
	return (1);
}

int		ft_alpha(char str)
{
	if ((str < 'a' && str > 'Z') || str < 'A' || str > 'z')
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int		cpt;

	cpt = 0;
	while (str[cpt] != '\0')
	{
		if (str[cpt] <= 'z' && str[cpt] >= 'a' && (cpt == 0 ||
				(ft_alpha(str[cpt - 1]) == 0 &&
				ft_num(str[cpt - 1]) == 0)))
			str[cpt] -= 32;
		else if (str[cpt] <= 'Z' && str[cpt] >= 'A' && cpt > 0 &&
					(ft_alpha(str[cpt - 1]) == 1 ||
					ft_num(str[cpt - 1]) == 1))
			str[cpt] += 32;
		cpt++;
	}
	return (str);
}
