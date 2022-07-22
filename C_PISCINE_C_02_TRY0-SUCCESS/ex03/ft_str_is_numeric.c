/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 20:39:45 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/18 22:58:09 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	char_is_digit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_str_is_numeric(char *str)
{
	unsigned int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (!char_is_digit(str[idx]))
			return (0);
		idx++;
	}
	return (1);
}
