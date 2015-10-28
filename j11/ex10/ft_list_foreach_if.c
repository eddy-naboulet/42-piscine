/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 11:49:36 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/28 11:50:15 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
		void *data_ref, int (*cmp)())
{
	while (begin_list != (void *)0)
	{
		if (cmp(begin_list->data, data_ref) == 0)
			(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}
