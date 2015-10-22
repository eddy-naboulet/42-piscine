/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 00:13:38 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/23 00:13:40 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base == 1)
		return (0);
	if ((base % 2) == 0)
		base = base / 2;
	else
		base = base * 3 + 1;
	return (1 + ft_collatz_conjecture(base));
}
