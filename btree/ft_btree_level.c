/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_level.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 01:16:05 by roalvare          #+#    #+#             */
/*   Updated: 2020/05/03 01:40:32 by roalvare         ###   ########.fr       */
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

// void	btree_apply_by_level(t_btree *root, void(*func)(void *item, int current_level, int is_first_elem))
// (
	
// )
