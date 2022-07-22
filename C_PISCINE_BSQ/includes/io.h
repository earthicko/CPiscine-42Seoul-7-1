/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:04:05 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 10:12:21 by seonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H
# include "map.h"
# include "t_string.h"

void		ft_putstr(char *str, int fd);
void		print_map_error(void);
void		print_map(t_charmap *charmap);
t_string	*read_file_to_str(int fd, char end);

#endif
