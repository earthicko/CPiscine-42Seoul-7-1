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

#include <stdlib.h>

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

int	ft_itoa_unsigned(char *dst, int nb)
{
	int		digit;
	int		i_write;

	if (nb == 0)
		return (0);
	digit = nb % 10;
	if (digit < 0)
		digit = -digit;
	i_write = ft_itoa_unsigned(dst, nb / 10);
	dst[i_write] = digit + '0';
	return (i_write + 1);
}

char	*ft_itoa(int nbr)
{
	int		l_itoa;
	char	*result;

	l_itoa = get_len_itoa(nbr);
	result = (char *)malloc(sizeof(char) * (l_itoa + 1));
	if (result == NULL)
		return (NULL);
	if (nbr == 0)
		result[0] = '0';
	else if (nbr < 0)
	{
		result[0] = '-';
		ft_itoa_unsigned(result + 1, nbr);
	}
	else
		ft_itoa_unsigned(result, nbr);
	result[l_itoa] = '\0';
	return (result);
}
