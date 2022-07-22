/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:44:07 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/23 15:16:35 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_state(int *i_rows)
{
	int		i;
	char	buffer;

	i = 0;
	while (i < 10)
	{
		buffer = i_rows[i] + '0';
		write(1, &buffer, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	set_state(int i_col, int i_row, int *state, int val)
{
	int	i_upleft;
	int	i_upright;

	i_upleft = 10 + i_col - i_row + 9;
	i_upright = 30 + i_col + i_row;
	state[i_row] = val;
	state[i_upleft] = val;
	state[i_upright] = val;
}

int	check_queen(int i_col, int i_row, int *state)
{
	int	i_upleft;
	int	i_upright;

	i_upleft = 10 + i_col - i_row + 9;
	i_upright = 30 + i_col + i_row;
	if (state[i_row] || state[i_upleft] || state[i_upright])
		return (1);
	return (0);
}

void	place_queen(int i_col, int *i_rows, int *state, int *counter)
{
	int	i_row;

	if (i_col == 10)
	{
		print_state(i_rows);
		(*counter)++;
	}
	i_row = 0;
	while (i_row < 10)
	{
		if (!check_queen(i_col, i_row, state))
		{
			set_state(i_col, i_row, state, 1);
			i_rows[i_col] = i_row;
			place_queen(i_col + 1, i_rows, state, counter);
			set_state(i_col, i_row, state, 0);
			i_rows[i_col] = -1;
		}
		i_row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	counter;
	int	state[49];
	int	i_rows[10];
	int	i;

	i = 0;
	while (i < 49)
		state[i++] = 0;
	i = 0;
	while (i < 10)
		i_rows[i++] = -1;
	counter = 0;
	place_queen(0, i_rows, state, &counter);
	return (counter);
}
