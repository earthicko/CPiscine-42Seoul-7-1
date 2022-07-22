/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:33:44 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/16 12:17:34 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	idx_max_dest;
	int	idx_max_curr;
	int	val_max_curr;
	int	idx_search;

	idx_max_dest = size - 1;
	while (0 <= idx_max_dest)
	{
		val_max_curr = -2147483648;
		idx_max_curr = -1;
		idx_search = 0;
		while (idx_search <= idx_max_dest)
		{
			if (val_max_curr <= tab[idx_search])
			{
				val_max_curr = tab[idx_search];
				idx_max_curr = idx_search;
			}
			idx_search++;
		}
		swap(&(tab[idx_max_dest]), &(tab[idx_max_curr]));
		idx_max_dest--;
	}
}
