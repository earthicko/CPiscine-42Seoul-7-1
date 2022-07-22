/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:09:10 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 22:09:11 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

t_string	*read_file_to_str(int fd)
{
	char		c;
	int			read_status;
	t_string	*buffer;

	buffer = string_init(8);
	while (1)
	{
		read_status = read(fd, &c, 1);
		if (read_status == 0)
			break ;
		if (read_status < 0)
			return (string_del(buffer));
		if (string_append(buffer, c) == -1)
			return (string_del(buffer));
	}
	return (buffer);
}
