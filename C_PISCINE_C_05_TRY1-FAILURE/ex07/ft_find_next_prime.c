/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:40:30 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/23 15:08:53 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	div;

	if (nb < 2)
		return (0);
	div = 2;
	while (div <= nb / 2)
	{
		if (nb % div == 0)
			return (0);
		div++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	if (ft_is_prime(nb))
		return (nb);
	if (nb % 2 == 0)
		return (ft_find_next_prime(nb + 1));
	else
		return (ft_find_next_prime(nb + 2));
}	
