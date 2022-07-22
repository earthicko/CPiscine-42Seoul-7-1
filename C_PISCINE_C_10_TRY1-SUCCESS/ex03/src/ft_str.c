/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:25:15 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 22:25:16 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include <stdlib.h>

int	ft_strncmp(char *a, char *b, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		if (a[i] != b[i])
			return (0);
	return (1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcpy(char *dst, char *src)
{
	int	idx;

	idx = 0;
	while (src[idx])
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = '\0';
	return (dst);
}

char	**create_strarr(int size)
{
	char	**strarr;
	int		i;

	strarr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!strarr)
		return (NULL);
	i = 0;
	while (i < size + 1)
	{
		strarr[i] = NULL;
		i++;
	}
	return (strarr);
}
