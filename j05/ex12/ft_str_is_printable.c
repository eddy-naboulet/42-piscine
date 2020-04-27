/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 18:41:15 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/17 18:42:06 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_printable(char *str)
{
	int		cpt;

	cpt = 0;
	while (str[cpt] != '\0')
	{
		if ((str[cpt] <= 32 && str[cpt] >= 0) || str[cpt] == 127)
			return (0);
		cpt++;
	}
	return (1);
}
