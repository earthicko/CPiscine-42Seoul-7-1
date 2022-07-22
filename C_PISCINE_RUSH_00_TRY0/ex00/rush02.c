/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 13:15:42 by seonjeon          #+#    #+#             */
/*   Updated: 2022/04/17 13:15:49 by seonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	put_appropriate_char(int x_pos, int y_pos, int x, int y)
{
	if ((1 < x_pos && x_pos < x) || (1 < y_pos && y_pos < y))
	{
		if ((1 < x_pos && x_pos < x) && (1 < y_pos && y_pos < y))
			ft_putchar(' ');
		else
			ft_putchar('B');
	}
	else
	{
		if (y_pos == 1)
			ft_putchar('A');
		else
			ft_putchar('C');
	}
}

void	rush(int x, int y)
{
	int	x_pos;
	int	y_pos;

	if (x <= 0)
		return ;
	y_pos = 1;
	while (y_pos <= y)
	{
		x_pos = 1;
		while (x_pos <= x)
		{
			put_appropriate_char(x_pos, y_pos, x, y);
			x_pos++;
		}
		ft_putchar('\n');
		y_pos++;
	}
}
