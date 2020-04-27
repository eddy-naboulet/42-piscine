/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboul@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:10:10 by enaboule          #+#    #+#             */
/*   Updated: 2015/11/26 16:10:34 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int		cpt;
	int		sgn;

	cpt = 0;
	sgn = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
	{
		str++;
	}
	if (*str == '-')
	{
		sgn = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		cpt = cpt * 10 + *str - '0';
		str++;
	}
	return (cpt * sgn);
}
