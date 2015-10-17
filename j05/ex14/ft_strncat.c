/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 18:42:57 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/17 18:43:11 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int nb)
{
	int		cpt;
	int		cpt2;

	cpt = 0;
	cpt2 = 0;
	while (dest[cpt] != '\0')
	{
		cpt++;
	}
	while (src[cpt2] != '\0' && cpt2 < nb)
	{
		dest[cpt] = src[cpt2];
		cpt++;
		cpt2++;
	}
	dest[cpt] = '\0';
	return (dest);
}
