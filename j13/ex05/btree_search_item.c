/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 12:03:43 by enaboule          #+#    #+#             */
/*   Updated: 2015/11/03 12:03:45 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void	*res;

	res = (void *)0;
	if (root == (void *)0)
		return (res);
	else
	{
		res = btree_search_item(root->left, data_ref, cmpf);
		if (res != (void *)0)
			return (res);
		if (cmpf(data_ref, root->item) == 0)
			return (root->item);
		res = btree_search_item(root->right, data_ref, cmpf);
		if (res != (void *)0)
			return (res);
	}
	return (res);
}
