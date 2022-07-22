/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:09:25 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/16 22:11:59 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	char_is_printable(char c)
{
	if (' ' <= c && c <= '~')
		return (1);
	return (0);
}

int	ft_str_is_printable(char *str)
{
	unsigned int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (!char_is_printable(str[idx]))
			return (0);
		idx++;
	}
	return (1);
}
