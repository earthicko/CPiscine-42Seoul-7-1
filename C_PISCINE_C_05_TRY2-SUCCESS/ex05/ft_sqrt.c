/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:31:58 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/25 10:51:22 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int			sqrt;
	long long	sq_sqrt;

	sqrt = 1;
	sq_sqrt = 1;
	while (sq_sqrt <= nb)
	{
		if (sq_sqrt == nb)
			return (sqrt);
		sqrt++;
		sq_sqrt = (long long) sqrt * (long long )sqrt;
	}
	return (0);
}
