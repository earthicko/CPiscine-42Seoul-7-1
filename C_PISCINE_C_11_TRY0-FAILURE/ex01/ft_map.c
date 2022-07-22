/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:51:26 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/01 14:51:28 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*mapped;
	int	i;

	mapped = (int *)malloc(sizeof(int) * length);
	if (!mapped)
		return (NULL);
	i = 0;
	while (i < length)
	{
		mapped[i] = f(tab[i]);
		i++;
	}
	return (mapped);
}
