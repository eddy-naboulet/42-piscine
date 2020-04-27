/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_insert_final.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 16:33:07 by enaboule          #+#    #+#             */
/*   Updated: 2015/11/06 16:51:21 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree_rb.h"

t_rb_node	*rb_insert_data(t_rb_node *cpt, t_rb_node **root, void *data,
			int (*cmpf)(void *, void*))
{
	if (*root == (void *)0)
	{
		*root = (t_rb_node *)malloc(sizeof(t_rb_node));
		(*root)->data = data;
		(*root)->color = RB_RED;
		(*root)->left = (void *)0;
		(*root)->right = (void *)0;
		(*root)->parent = cpt;
	}
	else
	{
		if (cmpf(data, (*root)->data) < 0)
			rb_insert_data(*root, &(*root)->left, data, cmpf);
		if (cmpf(data, (*root)->data) >= 0)
			rb_insert_data(*root, &(*root)->right, data, cmpf);
	}
	return (*root);
}

void		rb_insert(struct s_rb_node **root, void *data,
			int (*cmpf)(void *, void *))
{
	t_rb_node	*nw;

	nw = rb_insert_data((*root)->parent, root, data, cmpf);
	ft_tri(root, &nw);
}

t_rb_node	*ft_rot(t_rb_node **root, t_rb_node **racine, int direct)
{
	t_rb_node	*tmp;

	if (direct == 1)
	{
		tmp = (*root)->left;
		(*root)->left = tmp->right;
		(*root)->left->parent = *root;
		tmp->right = *root;
	}
	else
	{
		tmp = (*root)->right;
		(*root)->right = tmp->left;
		(*root)->right->parent = *root;
		tmp->left = *root;
	}
	(*root)->parent = tmp;
	*root = tmp;
	if ((*root)->parent == (void *)0)
		*racine = *root;
	if ((*root)->left != (void *)0)
		return ((*root)->left);
	else
		return ((*root)->right);
}

void		ft_tri2(t_rb_node **root, t_rb_node *root2)
{
	if (root2->parent->parent->left == root2->parent)
	{
		if (root2->parent->right == root2)
			root2 = ft_rot(&(root2->parent), root, 0);
		root2 = ft_rot(&(root2->parent), root, 1);
	}
	else
	{
		if (root2->parent->left == root2)
			root2 = ft_rot(&(root2->parent), root, 1);
		root2 = ft_rot(&(root2->parent), root, 0);
	}
	if (root2->parent->right != (void *)0)
		root2->parent->right->color = RB_RED;
	if (root2->parent->left != (void *)0)
		root2->parent->left->color = RB_RED;
	root2->parent->color = RB_BLACK;
}

void		ft_tri(t_rb_node **root, t_rb_node **root2)
{
	if ((*root2) != *root && (*root2)->parent->color == RB_RED)
	{
		if ((*root2)->parent->parent != (void *)0 && (*root2)->parent->parent
		->left != (void *)0 && (*root2)->parent->parent->right != (void *)0 &&
		(*root2)->parent->parent->left->color == RB_RED && (*root2)->parent->
		parent->right->color == RB_RED)
		{
			(*root2)->parent->parent->left->color = RB_BLACK;
			(*root2)->parent->parent->right->color = RB_BLACK;
			(*root2)->parent->parent->color = RB_RED;
			ft_tri(root, &((*root2)->parent->parent));
		}
		else if ((*root2)->parent->parent != (void *)0 && ((*root2)->parent->
		parent->left != (void *)0 || (*root2)->parent->parent->right !=
		(void *)0 || (*root2)->parent->parent->left->color != (*root2)->parent
		->parent->right->color))
			ft_tri2(root, *root2);
	}
	if ((*root)->color == RB_RED)
		(*root)->color = RB_BLACK;
}
