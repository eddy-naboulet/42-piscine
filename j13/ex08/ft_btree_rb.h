/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_rb.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 16:37:27 by enaboule          #+#    #+#             */
/*   Updated: 2015/11/06 16:38:13 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_RB_H
# define FT_BTREE_RB_H
# include <stdlib.h>

enum					e_rb_color
{
	RB_BLACK,
	RB_RED
};

typedef struct			s_rb_node
{
	struct s_rb_node	*parent;
	struct s_rb_node	*left;
	struct s_rb_node	*right;
	void				*data;
	enum e_rb_color		color;
}						t_rb_node;

void					rb_insert(struct s_rb_node **root, void *data,
						int (*cmpf)(void *, void *));
void					ft_tri(t_rb_node **root, t_rb_node **root2);
void					ft_tri2(t_rb_node **root, t_rb_node *root2);
t_rb_node				*rb_insert_data(t_rb_node *cpt, t_rb_node **root,
						void *data, int (*cmpf)(void *, void *));
t_rb_node				*ft_rot(t_rb_node **root, t_rb_node **racine,
						int direct);

#endif
