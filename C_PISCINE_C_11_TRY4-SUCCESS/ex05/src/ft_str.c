/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:35:56 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/01 16:35:57 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstrln(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
	ft_putchar('\n');
}

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
		write(1, "0\n", 2);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
	}
	print_nb_without_sign(nb);
	ft_putchar('\n');
}
