/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:30:58 by roalvare          #+#    #+#             */
/*   Updated: 2019/10/09 16:20:12 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	str = NULL;
	i = 0;
	if (!(str = malloc(count * size)))
		return (str);
	while (i < count * size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
