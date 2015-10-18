/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/18 16:36:00 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/18 16:36:03 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
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
	return (0);
}
