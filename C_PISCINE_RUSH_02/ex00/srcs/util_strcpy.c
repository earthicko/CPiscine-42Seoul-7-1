/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:57:34 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/01 19:57:35 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	idx;

	idx = 0;
	while (src[idx])
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	idx;

	idx = 0;
	while (src[idx] && idx < n)
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}
