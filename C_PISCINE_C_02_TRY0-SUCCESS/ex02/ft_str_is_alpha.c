/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 20:33:49 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/16 20:38:01 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	char_is_alpha(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

int	ft_str_is_alpha(char *str)
{
	unsigned int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (!char_is_alpha(str[idx]))
			return (0);
		idx++;
	}
	return (1);
}
