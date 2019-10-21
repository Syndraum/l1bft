/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:19:54 by syndraum          #+#    #+#             */
/*   Updated: 2019/10/21 11:33:57 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_rtr;
	t_list	*cursor;

	lst_rtr = NULL;
	cursor = lst_rtr;
	while (lst != NULL)
	{
		if (!(cursor = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&lst_rtr, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_rtr, cursor);
		lst = lst->next;
	}
	return (lst_rtr);
}
