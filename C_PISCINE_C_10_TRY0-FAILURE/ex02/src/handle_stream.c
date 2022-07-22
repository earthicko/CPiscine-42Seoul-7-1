/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stream.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:09:08 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 22:09:09 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	flush_buffer(int idx, t_string *buffer)
{
	while (idx < buffer->n)
	{
		write(STDOUT_FILENO, buffer->items + idx, 1);
		idx++;
	}
}

void	print_last_10_lines(t_string *buffer)
{
	int	nl_counter;
	int	idx;

	if (buffer->n == 0)
		return ;
	idx = buffer->n - 1;
	nl_counter = 0;
	if (buffer->items[idx] == '\n')
		nl_counter--;
	while (1)
	{
		if (buffer->items[idx] == '\n')
		{
			nl_counter++;
			if (nl_counter == 10)
			{
				idx++;
				break ;
			}
		}
		if (idx == 0)
			break ;
		idx--;
	}
	flush_buffer(idx, buffer);
}

void	print_last_n_bytes(t_string *buffer, int n)
{
	int	idx;

	if (buffer->n == 0)
		return ;
	idx = buffer->n - n;
	if (idx < 0)
		idx = 0;
	flush_buffer(idx, buffer);
}

void	handle_stream(int fd, int buf_size)
{
	t_string	*file_all;

	file_all = read_file_to_str(fd);
	if (buf_size == -1)
		print_last_10_lines(file_all);
	else
		print_last_n_bytes(file_all, buf_size);
}
