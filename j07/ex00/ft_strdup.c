/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 13:22:52 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/25 13:23:29 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		cpt;
	char	*dup;

	cpt = 0;
	while (src[cpt] != '\0')
	{
		cpt++;
	}
	dup = (char *)malloc(sizeof(char) * (cpt + 1));
	if (dup == (void*)0)
		return ((void*)0);
	while (cpt >= 0)
	{
		dup[cpt] = src[cpt];
		cpt--;
	}
	return (dup);
}
