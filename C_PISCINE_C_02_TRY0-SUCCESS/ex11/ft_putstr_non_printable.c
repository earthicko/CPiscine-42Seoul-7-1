/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 13:18:04 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/18 23:00:03 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	unsigned_dec_to_single_hex(char dec)
{
	if (dec < 16)
		return ("0123456789abcdef"[(int)dec]);
	else
		return (-1);
}

void	put_non_printable_char(char c)
{
	char	first;
	char	second;
	char	mask;

	mask = 0xF;
	write(1, "\\", 1);
	first = (c >> 4) & mask;
	second = c & mask;
	first = unsigned_dec_to_single_hex(first);
	second = unsigned_dec_to_single_hex(second);
	write(1, &first, 1);
	write(1, &second, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (' ' <= str[idx] && str[idx] <= '~')
			write(1, &str[idx], 1);
		else
			put_non_printable_char(str[idx]);
		idx++;
	}
}
