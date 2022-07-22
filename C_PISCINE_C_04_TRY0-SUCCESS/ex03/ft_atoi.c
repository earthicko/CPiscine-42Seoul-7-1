/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:20:31 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/21 17:26:47 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	idx;
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	idx = 0;
	while (str[idx] == ' ' || ('\t' <= str[idx] && str[idx] <= '\r'))
		idx++;
	while (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			sign *= -1;
		idx++;
	}
	while ('0' <= str[idx] && str[idx] <= '9')
	{
		result *= 10;
		result += (str[idx] - '0');
		idx++;
	}
	return (sign * result);
}
