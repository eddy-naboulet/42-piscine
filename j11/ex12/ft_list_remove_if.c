/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 11:51:29 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/29 18:39:13 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*stock;
	t_list	*tmp;

	while (*begin_list != (void *)0 && cmp((*begin_list)->data,
		data_ref) == 0)
	{
		stock = *begin_list;
		*begin_list = (*begin_list)->next;
		free(stock);
	}
	tmp = *begin_list;
	while (tmp != (void *)0 && tmp->next != (void *)0)
	{
		stock = tmp->next;
		if (cmp(stock->data, data_ref) == 0)
		{
			tmp->next = stock->next;
			free(stock);
		}
		tmp = tmp->next;
	}
}
