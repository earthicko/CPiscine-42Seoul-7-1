/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:09:03 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 22:09:04 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	ft_atoi(char *str)
{
	int	idx;
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	idx = 0;
	while (str[idx] == ' ' || ('\t' <= str[idx] && str[idx] <= '\r'))
		idx++;
	if (str[idx] == '-')
	{
		sign = -1;
		idx++;
	}
	else if (str[idx] == '+')
		idx++;
	while ('0' <= str[idx] && str[idx] <= '9')
	{
		result *= 10;
		result += (str[idx] - '0');
		idx++;
	}
	return (sign * result);
}

void	ft_putstr(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	idx;

	idx = 0;
	while (s1[idx] == s2[idx] && !(s1[idx] == '\0' && s2[idx] == '\0'))
		idx++;
	return ((int)(s1[idx] - s2[idx]));
}
