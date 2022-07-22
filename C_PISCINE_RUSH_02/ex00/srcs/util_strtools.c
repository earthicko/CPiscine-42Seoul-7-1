/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_strtools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:57:36 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/01 19:57:40 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ft.h"
#include "../includes/strtools.h"

int	is_input_valid_num(char *num)
{
	if (num[0] == '\0')
		return (0);
	while (*num)
	{
		if (!(*num >= '0' && *num <= '9'))
			return (0);
		num++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (*str++)
		idx++;
	return (idx);
}

int	ft_atoi(char *str)
{
	int	idx;
	int	flag;
	int	result;

	idx = 0;
	flag = 1;
	result = 0;
	while (str[idx] == ' ')
		idx++;
	while (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			flag *= -1;
		idx++;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		result *= 10;
		result += str[idx] - '0';
		idx++;
	}
	return (flag * result);
}

int	count_word(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && in_charset(*str, charset))
			str++;
		if (*str && !in_charset(*str, charset))
		{
			count++;
			while (*str && !in_charset(*str, charset))
				str++;
		}
	}
	return (count);
}

int	listlen(char **strs)
{
	int	len;

	len = 0;
	while (strs[len] != 0)
		len++;
	return (len);
}
