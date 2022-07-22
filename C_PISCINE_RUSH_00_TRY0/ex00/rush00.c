/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:20:21 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/16 18:38:37 by donghyle         ###   ########.fr       */
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
		else if (x_pos == 1 || x_pos == x)
			ft_putchar('|');
		else
			ft_putchar('-');
	}
	else
		ft_putchar('o');
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
