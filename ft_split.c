/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:53:31 by roalvare          #+#    #+#             */
/*   Updated: 2019/10/14 14:08:13 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strachr(const char *s, int c)
{
	int		i;
	char	*chaine;

	i = -1;
	chaine = (char*)s;
	while (chaine[++i])
	{
		if (chaine[i] == c)
			return (&chaine[i]);
	}
	return (&chaine[i]);
}

static void	free_tab(char **tab, int index)
{
	int i;

	i = 0;
	while (i < index)
	{
		free(tab[i]);
		i++;
	}
}

static int	fill_tab(char *s, char c, char **tab)
{
	int		i;
	char	*cursor;

	i = 0;
	cursor = s;
	while (*cursor)
	{
		if (ft_strachr(cursor, c) == cursor)
		{
			cursor += 1;
			s = cursor;
		}
		else
		{
			cursor = ft_strachr(cursor, c);
			if (!(tab[i] = calloc(cursor - s + 1, sizeof(char))))
			{
				free_tab(tab, i);
				return (0);
			}
			ft_strlcat(tab[i], s, cursor - s + 1);
			i++;
		}
	}
	return (1);
}

char		**ft_split(char const *s, char c)
{
	char	*cursor;
	int		count;
	char	**tab;

	cursor = (char*)s;
	count = 0;
	tab = NULL;
	while (*cursor)
	{
		if (ft_strachr(cursor, c) == cursor)
			cursor += 1;
		else
		{
			count++;
			cursor = ft_strachr(cursor, c);
		}
	}
	if (!(tab = calloc(count + 1, sizeof(char*))))
		return (tab);
	if (!fill_tab((char*)s, c, tab))
	{
		free(tab);
		return (NULL);
	}
	return (tab);
}
