/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:20:36 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/27 12:20:38 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	int		idx;
	char	*dest;

	idx = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dest == NULL)
		return (NULL);
	while (src[idx])
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

void	free_stock_str(struct s_stock_str *target, int lim)
{
	int	idx;

	idx = 0;
	while (idx < lim)
	{
		free(target->copy);
		target++;
		idx++;
	}
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					idx;
	struct s_stock_str	*array;

	array = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (array == NULL)
		return (NULL);
	idx = 0;
	while (idx < ac)
	{
		array[idx].size = ft_strlen(av[idx]);
		array[idx].str = av[idx];
		array[idx].copy = ft_strdup(av[idx]);
		if (array[idx].copy == NULL)
		{
			free_stock_str(array, idx);
			free(array);
			return (NULL);
		}
		idx++;
	}
	array[idx].str = 0;
	return (array);
}
