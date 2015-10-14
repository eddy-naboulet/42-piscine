/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 21:30:21 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/14 21:30:24 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_numbers(void)
{
	char	cpt;

	cpt = '0';
	while (cpt <= '9')
	{
		ft_putchar(cpt);
		cpt++;
	}
}
