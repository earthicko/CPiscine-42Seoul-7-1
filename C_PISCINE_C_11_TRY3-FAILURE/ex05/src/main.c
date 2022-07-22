/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:36:08 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/01 16:36:08 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	main(int argc, char **argv)
{
	int		val1;
	int		val2;
	char	op;

	if (argc != 4)
		return (0);
	op = parse_op(argv[2]);
	if (op == '\0')
	{
		ft_putstrln("0");
		return (0);
	}
	val1 = ft_atoi(argv[1]);
	val2 = ft_atoi(argv[3]);
	calculate(val1, val2, op);
	return (0);
}
