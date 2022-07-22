/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:05:26 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 10:05:27 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/solve.h"

void	fill_test_target_array(t_coord *arr, t_coord coord, int size)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (i < size - 1)
	{
		arr[len].r = coord.r;
		arr[len].c = coord.c;
		coord.c++;
		i++;
		len++;
	}
	i = 0;
	while (i < size)
	{
		arr[len].r = coord.r;
		arr[len].c = coord.c;
		coord.r--;
		i++;
		len++;
	}
	arr[len].r = -1;
	arr[len].c = -1;
}

t_coord	*generate_test_target_array(t_coord coord, int size)
{
	int		len;
	t_coord	*arr;

	if (size <= 1)
		return (NULL);
	len = (size - 1) * 2 + 1;
	arr = (t_coord *)malloc(sizeof(t_coord) * (len + 1));
	if (!arr)
		return (NULL);
	coord.r += (size - 1);
	fill_test_target_array(arr, coord, size);
	return (arr);
}

int	check_obstacle(t_map *map, t_coord coord, int size)
{
	int		i;
	t_coord	*target_arr;

	target_arr = generate_test_target_array(coord, size);
	if (!target_arr)
		return (-1);
	i = 0;
	while (target_arr[i].r != -1 && target_arr[i].c != -1)
	{
		if (map->map[target_arr[i].r][target_arr[i].c] == 0)
		{
			free(target_arr);
			return (0);
		}
		i++;
	}
	free(target_arr);
	return (1);
}

int	fill(t_map *map, t_coord coord, int size, int val)
{
	t_coord	*target_arr;
	int		i;

	target_arr = generate_test_target_array(coord, size);
	if (!target_arr)
		return (-1);
	i = 0;
	while (target_arr[i].r != -1 && target_arr[i].c != -1)
	{
		map->map[target_arr[i].r][target_arr[i].c] = val;
		i++;
	}
	free(target_arr);
	return (1);
}
