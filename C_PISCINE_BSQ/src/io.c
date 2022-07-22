/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:05:12 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 10:05:13 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/io.h"

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr(char *str, int fd)
{
	while (*str)
	{
		ft_putchar(*str, fd);
		str++;
	}
}

void	print_map_error(void)
{
	ft_putstr("map error\n", STDERR_FILENO);
}

void	print_map(t_charmap *charmap)
{
	int	r;
	int	c;

	r = 0;
	while (r < charmap->n_rows)
	{
		c = 0;
		while (c < charmap->n_cols)
		{
			ft_putchar(charmap->map[r][c], STDOUT_FILENO);
			c++;
		}
		ft_putchar('\n', STDOUT_FILENO);
		r++;
	}
}

t_string	*read_file_to_str(int fd, char end)
{
	char		c;
	int			read_status;
	t_string	*buffer;

	buffer = string_init(8);
	while (1)
	{
		read_status = read(fd, &c, 1);
		if (read_status <= 0)
			return (string_del(buffer));
		if (c == end)
			break ;
		if (string_append(buffer, c) == -1)
			return (string_del(buffer));
	}
	return (buffer);
}
