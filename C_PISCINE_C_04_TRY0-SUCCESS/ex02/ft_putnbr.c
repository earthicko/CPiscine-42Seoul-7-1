/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:52:42 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/15 20:12:38 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_digit(int digit)
{
	char	buffer;

	buffer = digit + '0';
	write(1, &buffer, 1);
}

void	print_nb_without_sign(int nb)
{
	int	digit;
	int	divider;

	divider = 1;
	while (!(-10 < nb / divider && nb / divider < 10))
	{
		divider *= 10;
	}
	while (divider > 0)
	{
		digit = nb / divider;
		nb = nb - (digit * divider);
		divider /= 10;
		if (digit < 0)
		{
			digit = -digit;
		}
		print_digit(digit);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
	}
	print_nb_without_sign(nb);
}
