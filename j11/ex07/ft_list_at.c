/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 11:46:08 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/28 14:47:12 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	cpt;

	cpt = 0;
	while (begin_list != (void*)0)
	{
		if (cpt == nbr)
			return (begin_list);
		begin_list = begin_list->next;
		cpt++;
	}
	return ((void*)0);
}
