/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 11:54:52 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/29 17:31:23 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*tmp;
	t_list	*stock;

	tmp = ft_create_elem(data);
	if (*begin_list == (void *)0)
		*begin_list = tmp;
	else if (cmp((*begin_list)->data, tmp->data) > 0)
	{
		tmp->next = *begin_list;
		*begin_list = tmp;
	}
	else
	{
		stock = *begin_list;
		while (stock != (void *)0)
		{
			if (cmp(stock->next->data, tmp->data) < 0)
			{
				tmp->next = stock->next;
				stock->next = tmp;
			}
			stock = stock->next;
		}
	}
}
