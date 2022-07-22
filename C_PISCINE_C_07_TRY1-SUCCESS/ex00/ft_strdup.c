/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:10:34 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/26 12:12:44 by donghyle         ###   ########.fr       */
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

char	*ft_strdup(char *src)
{
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dst == NULL)
		return (NULL);
	ft_strcpy(dst, src);
	return (dst);
}
