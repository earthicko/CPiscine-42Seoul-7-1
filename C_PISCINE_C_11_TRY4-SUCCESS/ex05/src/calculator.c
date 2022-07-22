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

void	init_operators(int (*operators[128])(int, int))
{
	int	i;

	i = 0;
	while (i < 128)
	{
		operators[i] = 0;
		i++;
	}
	operators['+'] = add;
	operators['-'] = subtract;
	operators['*'] = multiply;
	operators['/'] = divide;
	operators['%'] = modulo;
}

void	calculate(int val1, int val2, char op)
{
	int		(*operators[128])(int, int);

	init_operators(operators);
	if (op == '/' && val2 == 0)
		ft_putstrln("Stop : division by zero");
	else if (op == '%' && val2 == 0)
		ft_putstrln("Stop : modulo by zero");
	else
		ft_putnbr(operators[(int)op](val1, val2));
}
