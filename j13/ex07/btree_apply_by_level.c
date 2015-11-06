/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 16:57:34 by enaboule          #+#    #+#             */
/*   Updated: 2015/11/06 17:01:14 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

void		ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*stock;

	stock = *begin_list;
	if (*begin_list != (void *)0)
	{
		while ((*begin_list)->next != (void *)0)
		{
			*begin_list = (*begin_list)->next;
		}
		(*begin_list)->next = (t_list *)malloc(sizeof(t_list));
		(*begin_list)->next->data = data;
		(*begin_list)->next->next = (void *)0;
		*begin_list = stock;
	}
	else
	{
		*begin_list = (t_list *)malloc(sizeof(t_list));
		(*begin_list)->data = data;
		(*begin_list)->next = (void *)0;
	}
}

int			btree_level_count(t_btree *root)
{
	if (root == (void *)0)
		return (0);
	if (btree_level_count(root->left) > btree_level_count(root->right))
		return (1 + btree_level_count(root->left));
	return (1 + btree_level_count(root->right));
}

void		ft_liste(t_list **tab, t_btree *root, int lvl)
{
	if (root != (void *)0)
	{
		ft_list_push_back(&tab[lvl], root->item);
		ft_liste(tab, root->left, lvl + 1);
		ft_liste(tab, root->right, lvl + 1);
	}
}

void		ft_app(t_list *tab, int lvl, void (*applyf)(void *item,
			int current_level, int is_first_elem), int cpt)
{
	if (tab != (void *)0)
	{
		(*applyf)(tab->data, lvl, cpt);
		ft_app(tab->next, lvl, applyf, 0);
	}
}

void		btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int
			current_level, int is_first_elem))
{
	int		cpt;
	t_list	**tab;
	int		nb;

	nb = 0;
	cpt = btree_level_count(root);
	tab = (t_list **)malloc(sizeof(t_list *) * (cpt));
	while (nb < cpt)
	{
		tab[nb] = (void *)0;
		nb++;
	}
	ft_liste(tab, root, 0);
	nb = 0;
	while (nb < cpt)
	{
		ft_app(tab[nb], nb, applyf, 1);
		nb++;
	}
}
