/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:57:41 by roalvare          #+#    #+#             */
/*   Updated: 2019/10/10 18:22:23 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa(int n)
{
	char	*number;
	int		len;
	int		tmp;
	int		i;

	number = NULL;
	len = 0;
	tmp = n;
	i = 0;
	while (tmp > 0)
	{
		len++;
		tmp /= 10;
	}
	tmp = n;
	printf("len = %d\n", len);
	if (!(number = calloc(len + 1, sizeof(char))))
		return (number);
	while (tmp > 0)
	{
		number[i] = (tmp % 10) + '0';
		tmp /= 10;
		i++; 
	}
	printf("result = %s\n", number);
	return (number);
}
