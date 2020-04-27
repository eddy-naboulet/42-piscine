/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 11:42:59 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/29 11:48:13 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
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
