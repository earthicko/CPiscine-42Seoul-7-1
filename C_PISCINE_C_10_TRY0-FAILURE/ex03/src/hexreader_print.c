/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexreader_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:25:27 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 22:25:27 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"
#include "ft_str.h"

void	print_linenum(t_hexreader *reader, int is_leftover)
{
	int				n_digits;
	unsigned int	div;
	unsigned int	digit;
	unsigned int	linenum;

	linenum = reader->n_line_printed;
	if (is_leftover)
		linenum += reader->n_byte_printed;
	n_digits = 7;
	if (reader->canonical_ascii)
		n_digits++;
	div = 1;
	while (n_digits > 1)
	{
		div *= N_BYTES;
		n_digits--;
	}
	while (div)
	{
		digit = linenum / div;
		linenum = linenum % div;
		div = div / N_BYTES;
		ft_putchar(g_hex_dict[digit], STDOUT_FILENO);
	}
}

void	print_8bytes_in_hex(t_hexreader *reader, int rear)
{
	int				i;
	char			*str;
	int				size;

	str = reader->buffer;
	size = 8 * (reader->n_byte_printed / 8) + reader->n_byte_printed;
	if (rear)
	{
		str = reader->buffer + 8;
		size = reader->n_byte_printed - 8;
	}
	if (reader->canonical_ascii)
		ft_putchar(' ', STDOUT_FILENO);
	i = 0;
	while (i < size && i < 8)
	{
		ft_putchar(' ', STDOUT_FILENO);
		ft_putbyte(str[i], STDOUT_FILENO);
		i++;
	}
	while (i < 8)
	{
		ft_putstr("   ", STDOUT_FILENO);
		i++;
	}
}

void	print_bytes_in_hex(t_hexreader *reader)
{
	print_8bytes_in_hex(reader, 0);
	print_8bytes_in_hex(reader, 1);
}

void	print_bytes_in_ascii(t_hexreader *reader)
{
	int	i;

	ft_putstr("  |", STDOUT_FILENO);
	i = 0;
	while (i < reader->n_byte_printed)
	{
		if (ft_isprint(reader->buffer[i]))
			ft_putchar(reader->buffer[i], STDOUT_FILENO);
		else
			ft_putchar('.', STDOUT_FILENO);
		++i;
	}
	ft_putchar('|', STDOUT_FILENO);
}

void	print_error_msg(char *file, char *exec_name)
{
	ft_putstr(basename(exec_name), STDERR_FILENO);
	ft_putstr(": ", STDERR_FILENO);
	ft_putstr(file, STDERR_FILENO);
	ft_putstr(": ", STDERR_FILENO);
	ft_putstr(strerror(errno), STDERR_FILENO);
	ft_putchar('\n', STDERR_FILENO);
	errno = 0;
}
