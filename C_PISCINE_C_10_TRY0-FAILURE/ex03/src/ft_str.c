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
#include <string.h>
#include <stdlib.h>

const char	*g_hex_dict = "0123456789abcdef";

void	ft_putstr(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], fd);
		i++;
	}
}

int	is_flag_c(char *str)
{
	if (str[0] == '-' && str[1] == 'C' && str[2] == '\0')
		return (1);
	return (0);
}

int	ft_strncmp(char *a, char *b, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		if (a[i] != b[i])
			return (0);
	return (1);
}

char	*ft_strdup(char *src)
{
	return (strdup(src));
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
