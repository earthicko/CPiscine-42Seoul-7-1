/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:12:57 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/26 12:16:59 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	long long	width;
	long long	idx;
	int			*buffer;
	int			cursor;

	if (min >= max)
		return (NULL);
	width = (long long)max - (long long)min;
	buffer = malloc(sizeof(int) * width);
	if (buffer == NULL)
		return (NULL);
	cursor = min;
	idx = 0;
	while (cursor < max)
	{
		buffer[idx] = cursor;
		cursor++;
		idx++;
	}
	return (buffer);
}
