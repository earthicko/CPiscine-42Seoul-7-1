/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:21:49 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/26 14:29:19 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		determine_sign(char *str, int *idx);
int		build_map_if_valid_atoi_base(char *base, int *map);
int		get_len_base_if_valid_itoa_base(char *base);
int		get_len_itoa(int nbr, int l_base);
int		ft_itoa_base_unsigned(char *dst, int nb, char *base, int l_base);

int	ft_atoi_base(char *str, char *base)
{
	int	idx;
	int	sign;
	int	result;
	int	l_base;
	int	table[128];

	l_base = build_map_if_valid_atoi_base(base, table);
	if (l_base < 2)
		return (0);
	result = 0;
	idx = 0;
	while (str[idx] == ' ' || ('\t' <= str[idx] && str[idx] <= '\r'))
		idx++;
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

char	*ft_itoa_base(int nbr, char *base)
{
	int		l_base;
	int		l_itoa;
	char	*result;

	l_base = get_len_base_if_valid_itoa_base(base);
	if (l_base < 2)
		return (NULL);
	l_itoa = get_len_itoa(nbr, l_base);
	result = (char *)malloc(sizeof(char) * (l_itoa + 1));
	if (result == NULL)
		return (NULL);
	if (nbr == 0)
	{
		result[0] = base[0];
		result[1] = '\0';
	}
	else if (nbr < 0)
	{
		result[0] = '-';
		ft_itoa_base_unsigned(result + 1, nbr, base, l_base);
	}
	else
		ft_itoa_base_unsigned(result, nbr, base, l_base);
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nbr_dec;
	int		table[128];
	char	*converted;

	if (build_map_if_valid_atoi_base(base_from, table) < 2)
		return (NULL);
	nbr_dec = ft_atoi_base(nbr, base_from);
	converted = ft_itoa_base(nbr_dec, base_to);
	if (converted == NULL)
		return (NULL);
	return (converted);
}	
