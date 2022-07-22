/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_row.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:05:17 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 10:05:18 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/io.h"
#include "../includes/arrays.h"

int	fill_row(t_map *map, t_string *buffer, int i_row)
{
	int	i;

	i = 0;
	while (i < buffer->n)
	{
		if (buffer->items[i] == map->empty)
			map->map[i_row][i] = 1;
		else if (buffer->items[i] == map->obstacle)
			map->map[i_row][i] = 0;
		else
			return (-1);
		i++;
	}
	return (0);
}

int	parse_first_row(t_map *map, int fd)
{
	t_string	*buffer;
	int			wrong_char;

	buffer = read_file_to_str(fd, '\n');
	if (!buffer)
		return (-1);
	map->n_cols = buffer->n;
	map->map = alloc_int_array_2(map->n_rows, map->n_cols);
	if (!map->map)
	{
		string_del(buffer);
		return (-1);
	}
	wrong_char = fill_row(map, buffer, 0);
	string_del(buffer);
	return (wrong_char);
}

int	parse_row(t_map *map, int fd, int i_row)
{
	t_string	*buffer;
	int			wrong_char;

	buffer = read_file_to_str(fd, '\n');
	if (!buffer)
		return (-1);
	if (buffer->n != map->n_cols)
	{
		string_del(buffer);
		return (-1);
	}
	wrong_char = fill_row(map, buffer, i_row);
	string_del(buffer);
	return (wrong_char);
}
