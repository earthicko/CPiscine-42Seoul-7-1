/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:12:00 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/15 20:03:55 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_int_below_100(int num)
{
	char	ten;
	char	one;

	ten = num / 10 + '0';
	one = num % 10 + '0';
	write(1, &ten, 1);
	write(1, &one, 1);
}

void	ft_print_comb2(void)
{
	int		first;
	int		second;

	first = 0;
	second = 1;
	while (first <= 98)
	{
		second = first + 1;
		while (second <= 99)
		{
			print_int_below_100(first);
			write(1, " ", 1);
			print_int_below_100(second);
			if (!(first == 98 && second == 99))
			{
				write(1, ", ", 2);
			}
			second++;
		}
		first++;
	}
}
