/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:37:24 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/25 10:52:02 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
