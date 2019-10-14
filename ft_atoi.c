/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:22:14 by roalvare          #+#    #+#             */
/*   Updated: 2019/10/14 14:06:45 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_return(char *str, int count)
{
	int result;
	int i;

	result = 0;
	i = 0;
	if (count == 0)
		return (0);
	while (i < count)
	{
		result *= 10;
		result += (*(str + i) - '0');
		i++;
	}
	return (result);
}

static int	ft_is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int i;
	int count;
	int signe;

	i = 0;
	count = 0;
	signe = 1;
	while (str[i] && ft_is_white_space(str[i]))
		i++;
	if (str[i] == '-')
	{
		signe *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		count++;
		i++;
	}
	return (ft_return((char*)&str[i - count], count) * signe);
}
