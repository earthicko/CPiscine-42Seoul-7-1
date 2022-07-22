/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:12:41 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/17 10:25:38 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	char_is_lowercase(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}

char	*ft_strupcase(char *str)
{
	unsigned int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (char_is_lowercase(str[idx]))
			str[idx] += ('A' - 'a');
		idx++;
	}
	return (str);
}
