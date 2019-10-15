/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:19:54 by syndraum          #+#    #+#             */
/*   Updated: 2019/10/15 16:10:24 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	*lst_rtr;
	t_list	*cursor;

	if (!(lst_rtr = ft_calloc(ft_lstsize(lst), sizeof(t_list))))
		return (NULL);
	cursor = lst_rtr;
	while (lst != NULL)
	{
		cursor->content = f(lst->content);
		cursor->next = NULL;
		if (cursor != lst_rtr)
			ft_lstadd_back(&lst_rtr, cursor);
		cursor++;
		lst = lst->next;
	}
	return (lst_rtr);
}
