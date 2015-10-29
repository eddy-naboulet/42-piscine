/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 11:52:16 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/29 11:17:32 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*stock;

	stock = *begin_list1;
	if (*begin_list1 != (void *)0)
	{
		while (stock->next != (void *)0)
		{
			stock = stock->next;
		}
		stock->next = begin_list2;
	}
	else
		*begin_list1 = begin_list2;
}
