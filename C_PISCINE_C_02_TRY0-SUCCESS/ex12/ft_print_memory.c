/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:11:56 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/18 22:55:10 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef unsigned int	t_uint;

void	put_mem_addr_hex(void *addr)
{
	long long	dec_addr;
	long long	divider;
	int			idx_hex;
	int			n_digits;

	dec_addr = (long long)addr;
	n_digits = sizeof(addr) * 2;
	divider = 1;
	while (n_digits > 1)
	{
		divider *= 16;
		n_digits--;
	}
	while (divider > 0)
	{
		idx_hex = dec_addr / divider;
		write(1, &("0123456789abcdef"[idx_hex]), 1);
		dec_addr = dec_addr % divider;
		divider /= 16;
	}
}

void	put_char_hex(char c)
{
	int		msb;
	int		lsb;
	char	mask;

	mask = 0xF;
	msb = (c >> 4) & mask;
	lsb = c & mask;
	write(1, &("0123456789abcdef"[msb]), 1);
	write(1, &("0123456789abcdef"[lsb]), 1);
}

void	put_memory_content_hex(void *addr, t_uint nbytes, t_uint size)
{
	t_uint		offset;

	offset = 0;
	while (offset < nbytes)
	{
		if (offset < size)
			put_char_hex(((char *)addr)[offset]);
		else
			write(1, "  ", 2);
		if (offset % 2 == 1)
			write(1, " ", 1);
		offset++;
	}
}

void	put_memory_content_char(void *addr, t_uint nbytes, t_uint size)
{
	t_uint	offset;
	char	buffer;

	offset = 0;
	while (offset < nbytes && offset < size)
	{
		buffer = ((char *)addr)[offset];
		if (' ' <= buffer && buffer <= '~')
			write(1, &buffer, 1);
		else
			write(1, ".", 1);
		offset++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	while (size > 0)
	{
		put_mem_addr_hex(addr);
		write(1, ": ", 2);
		put_memory_content_hex(addr, sizeof(addr) * 2, size);
		put_memory_content_char(addr, sizeof(addr) * 2, size);
		write(1, "\n", 1);
		if (size < 16)
			break ;
		size -= 16;
		addr += 16;
	}
	return (addr);
}
