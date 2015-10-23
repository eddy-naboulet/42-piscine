/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 18:42:25 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/23 13:51:15 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int		cpt;
	int		cpt2;

	cpt = 0;
	cpt2 = 0;
	while (dest[cpt] != '\0')
	{
		cpt++;
	}
	while (src[cpt2] != '\0')
	{
		dest[cpt] = src[cpt2];
		cpt++;
		cpt2++;
	}
	dest[cpt] = '\0';
	return (dest);
}
