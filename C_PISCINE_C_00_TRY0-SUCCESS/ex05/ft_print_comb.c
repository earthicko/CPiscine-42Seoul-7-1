/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:09:49 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/15 19:59:07 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	digits[3];

	digits[0] = '0';
	while (digits[0] <= '7')
	{
		digits[1] = digits[0] + 1;
		while (digits[1] <= '8')
		{
			digits[2] = digits[1] + 1;
			while (digits[2] <= '9')
			{
				write(1, digits, 3);
				if (digits[0] < '7')
				{
					write(1, ", ", 2);
				}
				digits[2]++;
			}
			digits[1]++;
		}
		digits[0]++;
	}
}
