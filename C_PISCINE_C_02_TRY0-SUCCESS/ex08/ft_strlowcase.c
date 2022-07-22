/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:16:13 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/18 22:58:32 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	char_is_uppercase(char c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

char	*ft_strlowcase(char *str)
{
	unsigned int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (char_is_uppercase(str[idx]))
			str[idx] += ('a' - 'A');
		idx++;
	}
	return (str);
}
