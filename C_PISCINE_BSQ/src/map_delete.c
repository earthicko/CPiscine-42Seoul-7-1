/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:05:19 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 10:05:20 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/map.h"
#include "../includes/arrays.h"

t_map	*delete_map(t_map *map)
{
	if (map->map)
		delete_int_array_2(map->map, map->n_rows);
	free(map);
	return (NULL);
}

int	delete_charmap(t_charmap *charmap)
{
	if (charmap->map)
		delete_char_array_2(charmap->map, charmap->n_rows);
	free(charmap);
	return (0);
}
