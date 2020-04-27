/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 12:00:54 by enaboule          #+#    #+#             */
/*   Updated: 2015/11/03 12:00:56 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree		*btree_create_node(void *item)
{
	t_btree	*tree1;

	tree1 = (t_btree *)malloc(sizeof(t_btree));
	tree1->item = item;
	tree1->left = NULL;
	tree1->right = NULL;
	return (tree1);
}
