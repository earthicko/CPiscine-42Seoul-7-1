/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:57:22 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/02 20:57:23 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	same_sign(int a, int b)
{
	if (a > 0 && b > 0)
		return (1);
	if (a < 0 && b < 0)
		return (1);
	if (a == 0 && b == 0)
		return (1);
	return (0);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	dir;
	int	order;

	dir = 0;
	length--;
	while (length > 0)
	{
		order = f(tab[length], tab[length - 1]);
		if (order != 0)
		{
			if (dir == 0)
				dir = order;
			else if (!same_sign(dir, order))
				return (0);
		}
		length--;
	}
	return (1);
}
