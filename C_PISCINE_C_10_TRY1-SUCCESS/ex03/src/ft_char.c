/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:25:13 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 22:25:14 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

int	ft_isprint(unsigned char c)
{
	if (' ' <= c && c <= '~')
		return (1);
	return (0);
}

void	ft_putchar(unsigned char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putbyte(unsigned char byte, int fd)
{
	ft_putchar(HEX_DICT[(byte / N_BYTES)], fd);
	ft_putchar(HEX_DICT[(byte % N_BYTES)], fd);
}
