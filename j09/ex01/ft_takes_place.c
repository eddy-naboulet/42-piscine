/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 18:13:10 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/22 18:15:07 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_takes_places(int hour)
{
	if (hour == 0 || hour == 24)
		printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 A.M. AND %d.00 A.M.\n"
		, 12, 1);
	else if (hour == 12)
		printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 P.M. AND %d.00 P.M.\n"
		, 12, 1);
	else if (hour == 23)
		printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 P.M. AND %d.00 A.M.\n"
		, 11, 12);
	else if (hour == 11)
		printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 A.M. AND %d.00 P.M.\n"
		, 11, 12);
	else if (hour <= 10 && hour >= 1)
		printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 A.M. AND %d.00 A.M.\n"
		, hour, hour + 1);
	else if (hour >= 13 && hour <= 22)
		printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 P.M. AND %d.00 P.M.\n"
		, hour - 12, hour - 11);
}
