/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:28:29 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/15 23:33:13 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	l_idx;
	int	r_idx;

	l_idx = 0;
	r_idx = size - 1;
	while (l_idx < r_idx)
	{
		swap(&tab[l_idx], &tab[r_idx]);
		l_idx++;
		r_idx--;
	}
}
