/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:04:20 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 10:11:12 by seonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H
# include "map.h"

int	solve(t_map *map);
int	check_obstacle(t_map *map, t_coord coord, int size);
int	fill(t_map *map, t_coord coord, int size, int val);

#endif
