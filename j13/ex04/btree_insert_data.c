/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 12:03:09 by enaboule          #+#    #+#             */
/*   Updated: 2015/11/06 16:32:54 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void			btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	t_btree	*stock;

	stock = *root;
	if (*root == (void *)0)
		*root = btree_create_node(item);
	else
	{
		if (cmpf(item, (*root)->item) < 0)
			btree_insert_data(&(*root)->left, item, cmpf);
		if (cmpf(item, (*root)->item) >= 0)
			btree_insert_data(&(*root)->right, item, cmpf);
	}
}
