/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:42:39 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/25 13:03:40 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	skip_whitespace(char *str, int *idx)
{
	while (str[*idx] == ' ' || ('\t' <= str[*idx] && str[*idx] <= '\r'))
		(*idx)++;
}

int	determine_sign(char *str, int *idx)
{
	int	sign;

	sign = 1;
	while (str[*idx] == '-' || str[*idx] == '+')
	{
		if (str[*idx] == '-')
			sign *= -1;
		(*idx)++;
	}
	return (sign);
}

int	build_conversion_table(char *base, int *table)
{
	int		l_base;
	char	c;
	int		i;

	i = 0;
	while (i < 128)
		table[i++] = -1;
	l_base = 0;
	while (base[l_base] != '\0')
	{
		c = base[l_base];
		if (c == '+' || c == '-')
			return (0);
		if (c == ' ' || ('\t' <= c && c <= '\r'))
			return (0);
		if (table[(int)c] != -1)
			return (0);
		table[(int)c] = l_base;
		l_base++;
	}
	return (l_base);
}

int	ft_atoi_base(char *str, char *base)
{
	int	idx;
	int	sign;
	int	result;
	int	l_base;
	int	table[128];

	l_base = build_conversion_table(base, table);
	if (l_base < 2)
		return (0);
	result = 0;
	idx = 0;
	skip_whitespace(str, &idx);
	sign = determine_sign(str, &idx);
	while (1)
	{
		if (table[(int)str[idx]] == -1)
			break ;
		result *= l_base;
		result += table[(int)str[idx]];
		idx++;
	}
	return (sign * result);
}
