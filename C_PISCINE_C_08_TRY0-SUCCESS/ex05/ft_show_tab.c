/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:48:39 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/27 11:48:40 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstrln(char *str)
{
	while (*str)
		write(1, str++, 1);
	ft_putchar('\n');
}

void	print_nb_without_sign(int nb)
{
	int	digit;
	int	divider;

	divider = 1;
	while (!(-10 < nb / divider && nb / divider < 10))
		divider *= 10;
	while (divider > 0)
	{
		digit = nb / divider;
		nb = nb % divider;
		divider /= 10;
		if (digit < 0)
			digit = -digit;
		ft_putchar(digit + '0');
	}
}

void	ft_putnbrln(int nb)
{
	if (nb == 0)
	{
		write(1, "0\n", 2);
		return ;
	}
	if (nb < 0)
		write(1, "-", 1);
	print_nb_without_sign(nb);
	ft_putchar('\n');
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str != 0)
	{
		ft_putstrln(par->str);
		ft_putnbrln(par->size);
		ft_putstrln(par->copy);
		par++;
	}
}
