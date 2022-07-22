/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:25:18 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 22:25:19 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"
#include "ft_str.h"

int	print_line(t_hexreader *reader)
{
	if (ft_strncmp(reader->buffer, reader->buffer_prev, N_BYTES))
	{
		if (!reader->line_repeated)
		{
			reader->line_repeated = 1;
			ft_putstr("*\n", STDOUT_FILENO);
		}
	}
	else
	{
		reader->line_repeated = 0;
		print_linenum(reader, 0);
		print_bytes_in_hex(reader);
		if (reader->canonical_ascii)
			print_bytes_in_ascii(reader);
		ft_putchar('\n', STDOUT_FILENO);
		free(reader->buffer_prev);
		reader->buffer_prev = reader->buffer;
		reader->buffer = (char *)malloc(N_BYTES + 1);
		if (!reader->buffer)
			return (-1);
	}
	reader->n_line_printed += N_BYTES;
	reader->n_byte_printed = 0;
	return (0);
}

void	print_last_line(t_hexreader *reader)
{
	if (reader->n_byte_printed)
	{
		print_linenum(reader, 0);
		print_bytes_in_hex(reader);
		if (reader->canonical_ascii)
			print_bytes_in_ascii(reader);
		ft_putchar('\n', STDOUT_FILENO);
	}
	if (reader->all_files_error != 1 && reader->printed_atleast_once)
	{
		print_linenum(reader, 1);
		ft_putchar('\n', STDOUT_FILENO);
	}
}

int	hexdump_loop(int fd, int i_file, t_hexreader *reader)
{
	int	read_stat;

	while (1)
	{
		read_stat = read(fd, &reader->buffer[reader->n_byte_printed], 1);
		if (read_stat < 0)
			break ;
		reader->all_files_error = 0;
		if (read_stat == 0)
			break ;
		reader->printed_atleast_once = 1;
		reader->n_byte_printed++;
		if (reader->n_byte_printed == N_BYTES)
		{
			if (print_line(reader) != 0)
				return (-1);
		}
	}
	if (errno && i_file >= 0)
		puterror(reader->name_files[i_file], reader->exec_name);
	return (0);
}

int	hexdump_file(int i_file, t_hexreader *reader)
{
	int	fd;

	fd = open(reader->name_files[i_file], O_RDONLY);
	if (fd == -1)
		puterror(reader->name_files[i_file], reader->exec_name);
	else
	{
		if (hexdump_loop(fd, i_file, reader) != 0)
			return (-1);
	}
	return (0);
}

int	hexdump_files(t_hexreader *reader)
{
	int		i;
	char	*file_name;

	i = 0;
	while (i < reader->n_files)
	{
		if (hexdump_file(i, reader) != 0)
			return (-1);
		i++;
	}
	if (reader->all_files_error)
	{
		errno = 9;
		file_name = reader->name_files[reader->n_files - 1];
		puterror(file_name, reader->exec_name);
	}
	return (0);
}
