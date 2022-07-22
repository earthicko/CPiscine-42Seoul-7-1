/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:19:56 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/26 12:19:57 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (dst);
}

int	ft_strjoin_len(char **strs, int size, int sep_len)
{
	int	len;
	int	idx;

	if (size == 0)
		return (0);
	len = 0;
	idx = 0;
	while (idx < size)
	{
		len += ft_strlen(strs[idx]);
		len += sep_len;
		idx++;
	}
	len -= sep_len;
	return (len);
}

int	alloc_strjoin(char **dest, int size, char **strs, char *sep)
{
	int	len_joined;

	len_joined = ft_strjoin_len(strs, size, ft_strlen(sep));
	*dest = (char *)malloc(sizeof(char) * (len_joined + 1));
	return (len_joined);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len_joined;
	int		idx_strs;
	char	*str_joined;
	char	*cursor;

	len_joined = alloc_strjoin(&str_joined, size, strs, sep);
	if (str_joined == NULL)
		return (NULL);
	idx_strs = 0;
	cursor = str_joined;
	while (idx_strs < size)
	{
		cursor = ft_strcpy(cursor, strs[idx_strs]);
		if (idx_strs < size - 1)
			cursor = ft_strcpy(cursor, sep);
		idx_strs++;
	}
	*cursor = '\0';
	return (str_joined);
}
