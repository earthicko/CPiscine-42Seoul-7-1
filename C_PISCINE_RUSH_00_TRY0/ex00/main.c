/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:03:17 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/16 18:19:21 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);
int		atoi(const char *str);

int	main(int argc, char **argv)
{
	int	x;
	int	y;

	if (argc == 1)
	{
		x = 5;
		y = 5;
	}
	else if (argc == 3)
	{
		x = atoi(argv[1]);
		y = atoi(argv[2]);
	}
	else
		return (22);
	rush(x, y);
	return (0);
}

int	atoi(const char *str)
{
	int	idx;
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	idx = 0;
	while (str[idx] == 32 || (9 <= str[idx] && str[idx] <= 13))
		idx++;
	if (str[idx] == '-')
	{
		sign = -1;
		idx++;
	}
	else if (str[idx] == '+')
		idx++;
	while ('0' <= str[idx] && str[idx] <= '9')
	{
		result *= 10;
		result += (str[idx] - '0');
		idx++;
	}
	return (sign * result);
}
