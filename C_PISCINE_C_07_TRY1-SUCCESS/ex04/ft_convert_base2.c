/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:25:51 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/26 14:29:26 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_and_skip_sign(char *str, int *idx)
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

int	build_map_if_valid_base(char *base, int *map)
{
	int		l_base;
	char	c;
	int		i;

	i = 0;
	while (i < 128)
		map[i++] = -1;
	l_base = 0;
	while (base[l_base] != '\0')
	{
		c = base[l_base];
		if (c == '+' || c == '-')
			return (-1);
		if (c == ' ' || ('\t' <= c && c <= '\r'))
			return (-1);
		if (map[(int)c] != -1)
			return (-1);
		map[(int)c] = l_base;
		l_base++;
	}
	return (l_base);
}

int	get_len_itoa(int nbr, int l_base)
{
	int	len_itoa;

	if (nbr == 0)
		return (1);
	len_itoa = 0;
	if (nbr < 0)
		len_itoa++;
	while (nbr != 0)
	{
		nbr /= l_base;
		len_itoa++;
	}
	return (len_itoa);
}		

int	ft_itoa_base_unsigned(char *dst, int nb, char *base, int l_base)
{
	int	digit;
	int	i_write;

	if (nb == 0)
		return (0);
	digit = nb % l_base;
	if (digit < 0)
		digit = -digit;
	i_write = ft_itoa_base_unsigned(dst, nb / l_base, base, l_base);
	dst[i_write] = base[digit];
	return (i_write + 1);
}
