/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/18 16:35:37 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/18 16:35:51 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int		cpt;

	cpt = 0;
	while (argv[0][cpt] != '\0' && argc != 0)
	{
		ft_putchar(argv[0][cpt]);
		cpt++;
	}
	ft_putchar('\n');
	return (0);
}
