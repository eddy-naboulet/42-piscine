/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/18 16:36:17 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/18 16:36:19 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int		cpt;
	int		cpt2;

	cpt = argc - 1;
	cpt2 = 0;
	while (cpt > 0)
	{
		while (argv[cpt][cpt2] != '\0')
		{
			ft_putchar(argv[cpt][cpt2]);
			cpt2++;
		}
		cpt2 = 0;
		cpt--;
		ft_putchar('\n');
	}
	return (0);
}
