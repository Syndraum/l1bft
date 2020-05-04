/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:34:38 by roalvare          #+#    #+#             */
/*   Updated: 2020/05/04 03:32:52 by roalvare         ###   ########.fr       */
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

void	btree_insert_lst(t_btree **root, void *item, int (*cmpf)(void*, void*), t_list	**lst)
{
	if (*root == NULL && (*root = btree_create_node(item)))
		(*root)->item = item;
	else if (cmpf(item, (*root)->item) < 0)
	{
		ft_lstadd_front(lst, ft_lstnew(root));
		btree_insert_lst(&(*root)->left, item, cmpf, lst);
	}
	else
	{
		ft_lstadd_front(lst, ft_lstnew(root));
		btree_insert_lst(&(*root)->right, item, cmpf, lst);
	}
}

void	print_item(void *content)
{
	t_btree	*node;

	node = (t_btree*)content;
	ft_putstr_fd((char*)node->item, 1);
	ft_putstr_fd(" ==> ", 1);
}

void	btree_insert_egal(t_btree **root, void *item, int (*cmpf)(void*, void*))
{
	t_list	*lst;
	t_btree	**node;
	int		diff_level;

	lst = NULL;
	btree_insert_lst(root, item, cmpf, &lst);
	while (lst)
	{
		node = (t_btree**)lst->content;
		diff_level = btree_level_count((*node)->left) - btree_level_count((*node)->right);
		if (diff_level > 1)
			btree_rotate_right(node);
		else if (diff_level < -1)
			btree_rotate_left(node);
		free(lst);
		lst = lst->next;
	}
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
