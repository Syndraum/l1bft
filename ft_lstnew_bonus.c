/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syndraum <syndraum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:03:00 by syndraum          #+#    #+#             */
/*   Updated: 2019/10/11 14:11:51 by syndraum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list	*elmt;

	if(!(elmt = ft_calloc(1, sizeof(t_list))))
		return (NULL);
	elmt->content = content;
	elmt->next = NULL;
	return (elmt);
}