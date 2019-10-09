/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:37:34 by roalvare          #+#    #+#             */
/*   Updated: 2019/10/09 10:18:12 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*src_cpy;
	unsigned char		*dst_cpy;

	src_cpy = src;
	dst_cpy = dst;
	while (n-- > 0)
	{
		*dst_cpy = *src_cpy;
		dst_cpy++;
		src_cpy++;
	}
	return (dst);
}
