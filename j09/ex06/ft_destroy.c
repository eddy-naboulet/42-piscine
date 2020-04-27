/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 23:30:46 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/22 23:31:13 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ultimator.h"
#include <stdlib.h>

void	ft_destroy(char ***factory)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (factory != NULL)
	{
		while (factory[a] != NULL)
		{
			while (factory[a][b] != NULL)
			{
				free(factory[a][b]);
				b++;
			}
			free(factory[a]);
			a++;
			b = 0;
		}
		free(factory);
	}
}
