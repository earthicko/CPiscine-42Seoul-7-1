/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:05:08 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 10:05:11 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(char c)
{
	if (' ' <= c && c <= '~')
		return (1);
	return (0);
}

int	is_duplicate_3_chars(char *trio)
{
	if (trio[0] == trio[1])
		return (1);
	if (trio[1] == trio[2])
		return (1);
	if (trio[0] == trio[2])
		return (1);
	return (0);
}

int	ft_atoi_until(char *str, int nchars)
{
	int	idx;
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	idx = 0;
	while (str[idx] == ' ' || ('\t' <= str[idx] && str[idx] <= '\r'))
		idx++;
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	while (idx < nchars)
	{
		if (!('0' <= str[idx] && str[idx] <= '9'))
			return (-1);
		result *= 10;
		result += (str[idx] - '0');
		idx++;
	}
	return (sign * result);
}
