/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:00:44 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/17 10:21:13 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	char_is_uppercase(char c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

int	ft_str_is_uppercase(char *str)
{
	unsigned int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (!char_is_uppercase(str[idx]))
			return (0);
		idx++;
	}
	return (1);
}
