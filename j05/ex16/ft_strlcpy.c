/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 18:43:46 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/22 14:08:11 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	cpt;
	unsigned int	tmp;

	cpt = 0;
	tmp = 0;
	if (size > 0)
	{
		while (src[cpt] != '\0' && cpt < size - 1)
		{
			dest[cpt] = src[cpt];
			cpt++;
		}
		dest[cpt] = '\0';
	}
	while (src[cpt + tmp] != '\0')
	{
		tmp++;
	}
	return (cpt + tmp);
}
