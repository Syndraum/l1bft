/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:19:54 by syndraum          #+#    #+#             */
/*   Updated: 2019/10/14 12:37:28 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	*lst_rtr;

	lst_rtr = NULL;
	while (lst != NULL)
	{
		ft_lstadd_back(&lst_rtr, ft_lstnew(f(lst->content)));
		lst = lst->next;
	}
	return (lst_rtr);
}
