/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:35:50 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/01 16:35:51 by donghyle         ###   ########.fr       */
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

int	get_len_itoa(int nbr)
{
	int	len_itoa;

	if (nbr == 0)
		return (1);
	len_itoa = 0;
	if (nbr < 0)
		len_itoa++;
	while (nbr != 0)
	{
		nbr /= 10;
		len_itoa++;
	}
	return (len_itoa);
}
