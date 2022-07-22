/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:35:44 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/01 16:35:45 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	parse_op(char *arg)
{
	char	c;

	if (arg[1] != '\0')
		return ('\0');
	c = arg[0];
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		return (c);
	return ('\0');
}

char	*calculate(int val1, int val2, char op)
{
	char	*res_str;

	if (op == '+')
		res_str = ft_itoa(val1 + val2);
	else if (op == '-')
		res_str = ft_itoa(val1 - val2);
	else if (op == '*')
		res_str = ft_itoa(val1 * val2);
	else if (op == '/')
	{
		if (val2 == 0)
			res_str = ft_strdup("Stop : division by zero");
		else
			res_str = ft_itoa(val1 / val2);
	}
	else if (op == '%')
	{
		if (val2 == 0)
			res_str = ft_strdup("Stop : modulo by zero");
		else
			res_str = ft_itoa(val1 % val2);
	}
	else
		res_str = 0;
	return (res_str);
}
