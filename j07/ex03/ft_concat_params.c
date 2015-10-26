/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 13:24:32 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/26 17:20:15 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*chain(int argc, char **argv, char *str);

char	*ft_concat_params(int argc, char **argv)
{
	int		cpt;
	int		cpt2;
	int		cpt3;
	char	*str;

	cpt = 1;
	cpt2 = 0;
	cpt3 = 0;
	while (cpt < argc)
	{
		while (argv[cpt][cpt2] != '\0')
		{
			cpt3++;
			cpt2++;
		}
		cpt2 = 0;
		cpt++;
	}
	str = (char *)malloc(sizeof(char) * (cpt + cpt3));
	return (chain(argc, argv, str));
}

char	*chain(int argc, char **argv, char *str)
{
	int		cpt;
	int		cpt2;
	int		cpt3;

	cpt = 1;
	cpt2 = 0;
	cpt3 = 0;
	while (cpt < argc)
	{
		while (argv[cpt][cpt2] != '\0')
		{
			str[cpt3] = argv[cpt][cpt2];
			cpt2++;
			cpt3++;
		}
		if (cpt < argc - 1)
			str[cpt3] = '\n';
		else
			str[cpt3] = '\0';
		cpt2 = 0;
		cpt++;
		cpt3++;
	}
	return (str);
}
