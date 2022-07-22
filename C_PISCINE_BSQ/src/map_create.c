/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:05:17 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 10:05:18 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_str.h"
#include "../includes/io.h"
#include "../includes/arrays.h"

int	is_valid_mapchars(char *trio)
{
	if (is_duplicate_3_chars(trio))
		return (0);
	if (!ft_isprint(trio[0]))
		return (0);
	if (!ft_isprint(trio[1]))
		return (0);
	if (!ft_isprint(trio[2]))
		return (0);
	return (1);
}

t_map	*create_map(int fd)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = NULL;
	if (parse_first_line(map, fd) == -1)
	{
		free(map);
		return (NULL);
	}
	if (!parse_map_lines(map, fd))
		return (NULL);
	return (map);
}

t_charmap	*create_charmap(int n_rows, int n_cols)
{
	t_charmap	*charmap;

	charmap = (t_charmap *)malloc(sizeof(t_charmap));
	if (!charmap)
		return (NULL);
	charmap->n_rows = n_rows;
	charmap->n_cols = n_cols;
	charmap->map = alloc_char_array_2(n_rows, n_cols);
	if (!charmap->map)
	{
		free(charmap);
		return (NULL);
	}
	return (charmap);
}
