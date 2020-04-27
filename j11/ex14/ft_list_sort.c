/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 11:53:05 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/29 17:19:40 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int		cpt;

	cpt = 0;
	while (begin_list != (void *)0)
	{
		begin_list = begin_list->next;
		cpt++;
	}
	return (cpt);
}

void	ft_swap(t_list *s1, t_list *s2)
{
	void	*tmp;

	tmp = s1->data;
	s1->data = s2->data;
	s2->data = tmp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*tmp;
	int		cpt;

	tmp = *begin_list;
	cpt = ft_list_size(*begin_list);
	if (tmp != (void *)0)
	{
		while (cpt >= 0)
		{
			while (tmp->next != (void *)0)
			{
				if (cmp(tmp->data, tmp->next->data) > 0)
					ft_swap(tmp, tmp->next);
				tmp = tmp->next;
			}
			cpt--;
			tmp = *begin_list;
		}
	}
}
