/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_strcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:57:31 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/01 19:57:33 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ft.h"
#include "../includes/strtools.h"

char	*str_realloc(char *src, int len_src, int len_new)
{
	char	*dst;

	if (len_new > len_src)
	{
		dst = (char *)malloc(sizeof(char) * (len_new + 1));
		if (!dst)
		{
			free(src);
			return (NULL);
		}
		ft_strcpy(dst, src);
		free(src);
		return (dst);
	}
	return (src);
}

char	*ft_append(char *src, char *append)
{
	int	len_src;
	int	len_app;

	if (!append)
	{
		free(src);
		return (NULL);
	}
	if (!src)
		return (NULL);
	len_src = ft_strlen(src);
	len_app = ft_strlen(append);
	src = str_realloc(src, len_src, len_src + len_app + 1);
	if (!src)
		return (NULL);
	ft_strcat_space(src, append);
	return (src);
}

char	*ft_strncat(char *dest, char *src, int size)
{
	char	*pos;

	pos = dest;
	while (*dest)
		dest++;
	while (*src && size--)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (pos);
}

char	*ft_strcat_space(char *dest, char *src)
{
	char	*pos;

	pos = dest;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = ' ';
	dest++;
	*dest = '\0';
	return (pos);
}
