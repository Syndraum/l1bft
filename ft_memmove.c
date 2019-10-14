/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:22:32 by roalvare          #+#    #+#             */
/*   Updated: 2019/10/14 14:47:07 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*src_cpy;
	unsigned char		*dst_cpy;

	src_cpy = src + len - 1;
	dst_cpy = dst + len - 1;
	while (len-- > 0)
	{
		*dst_cpy = *src_cpy;
		dst_cpy--;
		src_cpy--;
	}
	return (dst);
}
