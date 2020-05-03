/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:34:38 by roalvare          #+#    #+#             */
/*   Updated: 2020/05/03 19:10:23 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void*, void*))
{
	if (*root == NULL && (*root = btree_create_node(item)))
		(*root)->item = item;
	else if (cmpf(item, (*root)->item) < 0)
		btree_insert_data(&(*root)->left, item, cmpf);
	else
		btree_insert_data(&(*root)->right, item, cmpf);
}

void	btree_rotate_left(t_btree **root)
{
	t_btree	*pivot;

	if ((pivot = (*root)->right))
	{
		(*root)->right = pivot->left;
		pivot->left = *root;
		*root = pivot;
	}
}

void	btree_rotate_right(t_btree **root)
{
	t_btree	*pivot;

	if ((pivot = (*root)->left))
	{
		(*root)->left = pivot->right;
		pivot->right = *root;
		*root = pivot;
	}
}

int		v_strcmp(void *s1, void *s2)
{
	return (strcmp((char*)s1, (char*)s2));
}
