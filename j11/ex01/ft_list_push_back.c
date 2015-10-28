/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 11:41:39 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/28 12:08:22 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list		*stock;

	stock = *begin_list;
	if (*begin_list != (void *)0)
	{
		while ((*begin_list)->next != (void*)0)
		{
			*begin_list = (*begin_list)->next;
		}
		(*begin_list)->next = ft_create_elem(data);
		*begin_list = stock;
	}
	else
		*begin_list = ft_create_elem(data);
}
