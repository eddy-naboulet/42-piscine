/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 11:44:42 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/29 09:20:42 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void		ft_list_push_front(t_list **begin_list, void *data)
{
	t_list		*stock;

	stock = ft_create_elem(data);
	stock->next = *begin_list;
	*begin_list = stock;
}

t_list		*ft_list_push_params(int ac, char **av)
{
	int		cpt;
	t_list	*res;

	cpt = 0;
	res = (void*)0;
	while (cpt < ac)
	{
		ft_list_push_front(&res, av[cpt]);
		cpt++;
	}
	return (res);
}
