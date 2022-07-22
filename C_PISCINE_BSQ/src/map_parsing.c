/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:05:17 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 10:05:18 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/io.h"
#include "../includes/t_string.h"
#include "../includes/ft_str.h"
#include "../includes/arrays.h"

t_map	*parse_map_lines(t_map *map, int fd)
{
	int	i;

	if (parse_first_row(map, fd) == -1)
		return (delete_map(map));
	i = 1;
	while (i < map->n_rows)
	{
		if (parse_row(map, fd, i) == -1)
			return (delete_map(map));
		i++;
	}
	return (map);
}

int	parse_first_line(t_map *map, int fd)
{
	t_string	*buffer;

	buffer = read_file_to_str(fd, '\n');
	if (!buffer)
		return (-1);
	if (buffer->n < 3)
	{
		string_del(buffer);
		return (-1);
	}
	if (!is_valid_mapchars(buffer->items + buffer->n - 3))
	{
		string_del(buffer);
		return (-1);
	}
	map->empty = buffer->items[buffer->n - 3];
	map->obstacle = buffer->items[buffer->n - 2];
	map->full = buffer->items[buffer->n - 1];
	map->n_rows = ft_atoi_until(buffer->items, buffer->n - 3);
	string_del(buffer);
	if (map->n_rows <= 0)
		return (-1);
	return (0);
}
