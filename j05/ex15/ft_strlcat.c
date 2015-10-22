/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 18:43:29 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/22 13:57:22 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	cpt;
	unsigned int	cpt2;
	unsigned int	tmp;

	cpt = 0;
	cpt2 = 0;
	tmp = 0;
	if (size > 0)
	{
		while (dest[cpt] != '\0' && cpt < size)
			cpt++;
		while (src[cpt2] != '\0' && cpt < size - 1)
		{
			dest[cpt] = src[cpt2];
			cpt++;
			cpt2++;
		}
		if (cpt < size)
			dest[cpt] = '\0';
	}
	while (src[cpt2 + tmp] != '\0')
	{
		tmp++;
	}
	return (cpt + tmp);
}
