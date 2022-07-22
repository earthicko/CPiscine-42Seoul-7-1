/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:40:30 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/25 11:10:47 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_is_prime(int nb)
{
	long long	div;

	if (nb < 2)
		return (0);
	if (nb < 4)
		return (1);
	if (nb % 2 == 0)
		return (0);
	div = 3;
	while (div * div <= nb)
	{
		if (nb % div == 0)
			return (0);
		div += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	while (nb != INT_MAX)
	{
		if (ft_is_prime(nb))
			return (nb);
		if (nb % 2 == 0)
			nb += 1;
		else
			nb += 2;
	}
	if (ft_is_prime(nb))
		return (nb);
	else
		return (2);
}	
