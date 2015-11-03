/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 12:04:28 by enaboule          #+#    #+#             */
/*   Updated: 2015/11/03 12:04:33 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		btree_level_count(t_btree *root)
{
	if (root == (void *)0)
		return (0);
	if (btree_level_count(root->left) > btree_level_count(root->right))
		return (1 + btree_level_count(root->left));
	return (1 + btree_level_count(root->right));
}
