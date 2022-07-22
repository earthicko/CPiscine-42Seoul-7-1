/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:31:58 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/23 14:59:45 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	binary_search_sqrt(int nb, int lim_lower, int lim_upper)
{
	int	mid;
	int	sq_mid;

	if (lim_lower > lim_upper)
		return (0);
	mid = (lim_lower + lim_upper) / 2;
	sq_mid = mid * mid;
	if (sq_mid == nb)
		return (sq_mid);
	else if (sq_mid > nb)
		return (binary_search_sqrt(nb, lim_lower, mid - 1));
	else
		return (binary_search_sqrt(nb, mid + 1, lim_upper));
}

int	ft_sqrt(int nb)
{
	if (nb == 1)
		return (1);
	return (binary_search_sqrt(nb, 1, nb - 1));
}
