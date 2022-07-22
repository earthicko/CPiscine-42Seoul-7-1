/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:27:43 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/25 13:05:03 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_len_base_if_valid(char *base)
{
	int	l_base;
	int	is_used_char[128];
	int	i;

	i = 0;
	while (i < 128)
	{
		is_used_char[i] = 0;
		i++;
	}
	l_base = 0;
	while (base[l_base] != '\0')
	{
		if (base[l_base] == '+' || base[l_base] == '-')
			return (0);
		if (is_used_char[(int)base[l_base]])
			return (0);
		is_used_char[(int)base[l_base]] = 1;
		l_base++;
	}
	return (l_base);
}

void	putnbr_base_unsigned(int nb, char *base, int l_base)
{
	int	digit;

	if (nb == 0)
		return ;
	digit = nb % l_base;
	if (digit < 0)
		digit = -digit;
	putnbr_base_unsigned(nb / l_base, base, l_base);
	write(1, base + digit, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	l_base;

	l_base = get_len_base_if_valid(base);
	if (l_base < 2)
		return ;
	if (nbr < 0)
		write(1, "-", 1);
	if (nbr == 0)
	{
		write(1, base, 1);
		return ;
	}
	putnbr_base_unsigned(nbr, base, l_base);
}
