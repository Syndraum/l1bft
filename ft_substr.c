/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syndraum <syndraum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:30:12 by syndraum          #+#    #+#             */
/*   Updated: 2019/10/09 22:14:19 by syndraum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    int     mem;
    int     i;
    char    *str;

    i = 0;
    str = NULL;
    if (ft_strlen(s) < start)
        mem = 0;
    else if (ft_strlen(s) < start + len + 1)
        mem = ft_strlen(s) - start + 1;
    else
        mem = len;
    if (!(str = malloc((sizeof(char) * mem) + 1)))
        return (NULL);
    while (mem > i)
    {
        str[i] = s[start + i];
        i++;
    }
    return (str);
}