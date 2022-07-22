/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 21:17:32 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/15 20:16:12 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_digit(int digit)
{
	char	buffer;

	buffer = digit + '0';
	write(1, &buffer, 1);
}

void	print_arr_nbr(int *nbrs, int n_nbrs)
{
	int		i_nbrs;

	i_nbrs = 0;
	while (i_nbrs < n_nbrs)
	{
		print_digit(nbrs[i_nbrs]);
		i_nbrs++;
	}
}

void	print_combn_from(int *history, int cur_idx, int max_idx, int from)
{
	if (cur_idx == max_idx)
	{
		history[cur_idx] = from;
		print_arr_nbr(history, max_idx);
		if (history[0] + max_idx != 10)
			write(1, ", ", 2);
		return ;
	}
	while (from <= 9)
	{
		history[cur_idx] = from;
		print_combn_from(history, cur_idx + 1, max_idx, from + 1);
		from++;
	}
}

void	ft_print_combn(int n)
{
	int	history[10];

	print_combn_from(history, 0, n, 0);
}
