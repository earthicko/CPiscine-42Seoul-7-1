/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:20:13 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/26 12:20:14 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long long	width;
	long long	idx;
	int			cursor;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	width = (long long)max - (long long)min;
	*range = malloc(sizeof(int) * width);
	if (*range == NULL)
		return (-1);
	cursor = min;
	idx = 0;
	while (cursor < max)
	{
		(*range)[idx] = cursor;
		cursor++;
		idx++;
	}
	return (width);
}
