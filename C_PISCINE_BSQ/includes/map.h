/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:04:10 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 10:09:47 by seonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "t_string.h"

typedef struct s_coord
{
	int	r;
	int	c;
}	t_coord;

typedef struct s_map
{
	int		n_rows;
	int		n_cols;
	char	empty;
	char	obstacle;
	char	full;
	int		**map;
}			t_map;

typedef struct s_charmap
{
	int		n_rows;
	int		n_cols;
	char	**map;
}			t_charmap;

t_map		*create_map(int fd);
t_charmap	*create_charmap(int n_rows, int n_cols);
int			is_valid_mapchars(char *trio);
t_map		*delete_map(t_map *map);
int			delete_charmap(t_charmap *charmap);
t_map		*parse_map_lines(t_map *map, int fd);
int			parse_first_line(t_map *map, int fd);
int			parse_first_row(t_map *map, int fd);
int			parse_row(t_map *map, int fd, int i_row);

#endif
