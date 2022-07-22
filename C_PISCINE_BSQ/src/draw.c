/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:04:52 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 10:04:53 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/map.h"

t_coord	find_max_val(t_map *map)
{
	int		r;
	int		c;
	t_coord	max_position;
	int		max_size;

	max_size = -1;
	max_position.r = -1;
	max_position.c = -1;
	r = 0;
	while (r < map->n_rows)
	{
		c = 0;
		while (c < map->n_cols)
		{
			if (map->map[r][c] > max_size)
			{
				max_size = map->map[r][c];
				max_position.r = r;
				max_position.c = c;
			}
			c++;
		}
		r++;
	}
	return (max_position);
}

void	draw_empty_map(t_map *map, t_charmap *charmap)
{
	int	r;
	int	c;

	r = 0;
	while (r < map->n_rows)
	{
		c = 0;
		while (c < map->n_cols)
		{
			if (map->map[r][c] == 0)
				charmap->map[r][c] = map->obstacle;
			else
				charmap->map[r][c] = map->empty;
			c++;
		}
		r++;
	}
}

void	draw_square(t_map *map, t_charmap *charmap, int size, t_coord pos)
{
	int	r;
	int	c;

	r = 0;
	while (r < size)
	{
		c = 0;
		while (c < size)
		{
			charmap->map[pos.r + r][pos.c + c] = map->full;
			c++;
		}
		r++;
	}
}

t_charmap	*draw(t_map *map)
{
	t_charmap	*charmap;
	t_coord		max_position;
	int			max_size;

	charmap = create_charmap(map->n_rows, map->n_cols);
	if (!charmap)
		return (NULL);
	max_position = find_max_val(map);
	max_size = map->map[max_position.r][max_position.c];
	draw_empty_map(map, charmap);
	draw_square(map, charmap, max_size, max_position);
	return (charmap);
}
