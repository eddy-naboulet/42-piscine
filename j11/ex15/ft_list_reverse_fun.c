/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 11:53:38 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/28 11:54:25 by enaboule         ###   ########.fr       */
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

t_list		*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	cpt;

	cpt = 1;
	while (begin_list != (void*)0)
	{
		if (cpt == nbr)
			return (begin_list);
		begin_list = begin_list->next;
		cpt++;
	}
	return ((void*)0);
}

void		ft_list_reverse(t_list **begin_list)
{
	int		first;
	int		last;
	int		mid;
	t_list	*tmp;

	first = 1;
	last = ft_list_size(*begin_list);
	mid = last / 2;
	tmp = ft_list_at(*begin_list, last);
	while (first <= mid)
	{
		ft_swap(ft_list_at(*begin_list, first), ft_list_at(*begin_list, last));
		first++;
		last--;
	}
	*begin_list = tmp;
}

void		ft_list_reverse_fun(t_list *begin_list)
{
	ft_list_reverse(&begin_list);
}
