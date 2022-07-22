/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:57:56 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/17 10:21:02 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	char_is_lowercase(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}

int	ft_str_is_lowercase(char *str)
{
	unsigned int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (!char_is_lowercase(str[idx]))
			return (0);
		idx++;
	}
	return (1);
}
