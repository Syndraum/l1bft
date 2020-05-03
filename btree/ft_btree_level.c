/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_level.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 01:16:05 by roalvare          #+#    #+#             */
/*   Updated: 2020/05/03 02:36:00 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	btree_level_count(t_btree *root)
{
	int	left;
	int	right;

	if (!root)
		return (0);
	left = 1 + btree_level_count(root->left);
	right = 1 + btree_level_count(root->right);
	
	return (ft_max(left, right));
}

void	ft_listdelfirst(t_list **lst)
{
	t_list	*tmp;

	tmp = (*lst)->next;
	free(*lst);
	*lst = tmp;
}

void	btree_apply_by_level(t_btree *root, void(*func)(void *item, int current_level, int is_first_elem))
{
	t_list	*lst;
	t_btree	*node;
	int		level;

	lst = NULL;
	level = 0;
	ft_lstadd_front(&lst, ft_lstnew(root));
	while (lst)
	{
		node = (t_btree*)lst->content;
		ft_listdelfirst(&lst);
		func(node->item, level, 0);
		if (node->left)
			ft_lstadd_back(&lst, ft_lstnew(node->left));
		if (node->right)
			ft_lstadd_back(&lst, ft_lstnew(node->right));
		level++;
	}
}
