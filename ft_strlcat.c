/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:58:50 by roalvare          #+#    #+#             */
/*   Updated: 2019/10/08 14:58:54 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	int		j;
	size_t	lenght_dest;
	size_t	lenght_src;

	i = 0;
	j = 0;
	lenght_dest = ft_strlen(dst);
	lenght_src = ft_strlen(src);
	if (dstsize == 0)
		return (lenght_src);
	while (dst[i])
	{
		i++;
	}
	while (i < dstsize - 1 && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (lenght_dest > dstsize)
		return (lenght_src + dstsize);
	else
		return (lenght_dest + lenght_src);
}
