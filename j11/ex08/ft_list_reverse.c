/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 11:46:49 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/29 18:43:40 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_swap(t_list *s1, t_list *s2)
{
	void	*tmp;

	tmp = s1->data;
	s1->data = s2->data;
	s2->data = tmp;
}

int			ft_list_size(t_list *begin_list)
{
	int		cpt;

	cpt = 0;
	while (begin_list != (void*)0)
	{
		begin_list = begin_list->next;
		cpt++;
	}
	return (cpt);
}

void		ft_list_reverse(t_list **begin_list)
{
	int		first;
	int		last;
	t_list	*tmp;

	first = 1;
	last = ft_list_size(*begin_list);
	tmp = *begin_list;
	while (first < last)
	{
		while ((*begin_list != (void *)0) && (*begin_list)->next !=
			(void *)0 && first < last)
		{
			ft_swap(*begin_list, (*begin_list)->next);
			*begin_list = (*begin_list)->next;
			first++;
		}
		first = 1;
		*begin_list = tmp;
		last--;
	}
}
