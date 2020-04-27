/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/18 16:36:38 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/18 16:36:39 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_aff_ar(int argc, char **argv)
{
	int		cpt;
	int		cpt2;

	cpt = 1;
	cpt2 = 0;
	while (cpt < argc)
	{
		while (argv[cpt][cpt2] != '\0')
		{
			ft_putchar(argv[cpt][cpt2]);
			cpt2++;
		}
		cpt2 = 0;
		cpt++;
		ft_putchar('\n');
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

int		main(int argc, char **argv)
{
	int		cpt;
	int		cpt2;
	int		cpt3;

	cpt = 1;
	cpt2 = 0;
	cpt3 = 0;
	while (cpt3 < argc - 1)
	{
		while (cpt < argc - 1)
		{
			if (ft_strcmp(argv[cpt], argv[cpt + 1]) > 0)
			{
				ft_swap(&argv[cpt], &argv[cpt + 1]);
			}
			cpt++;
		}
		cpt3++;
		cpt = 1;
	}
	ft_aff_ar(argc, argv);
	return (0);
}
