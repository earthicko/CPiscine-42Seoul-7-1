/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:57:16 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/01 19:57:20 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isspace(char c)
{
	if (c == ' ' || ('\t' <= c && c <= '\r'))
		return (1);
	return (0);
}

int	ft_isprint(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

int	is_char_in_str(char *str, char c)
{
	int	pos;

	pos = 0;
	while (str[pos])
	{
		if (str[pos] == c)
			return (pos);
		pos++;
	}
	return (-1);
}
