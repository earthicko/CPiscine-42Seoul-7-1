/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:05:24 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 10:05:25 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mathtools.h"
#include "../includes/solve.h"

int	try_from(t_map *map, t_coord cursor)
{
	int	i;
	int	size;
	int	result;

	if (map->map[cursor.r][cursor.c] > 0)
	{
		size = map->map[cursor.r][cursor.c];
		while (++size <= min(map->n_cols - cursor.c, map->n_rows - cursor.r))
		{
			result = check_obstacle(map, cursor, size);
			if (result == 0)
				break ;
			if (result == -1)
				return (-1);
		}
		size--;
		map->map[cursor.r][cursor.c] = size;
		i = 1;
		while (++i <= size)
		{
			if (fill(map, cursor, i, size - i + 1) == -1)
				return (-1);
		}
	}
	return (0);
}

int	solve(t_map *map)
{
	t_coord	cursor;

	cursor.r = 0;
	while (cursor.r < map->n_rows)
	{
		cursor.c = 0;
		while (cursor.c < map->n_cols)
		{
			if (try_from(map, cursor) == -1)
				return (-1);
			cursor.c++;
		}
		cursor.r++;
	}
	return (0);
}
