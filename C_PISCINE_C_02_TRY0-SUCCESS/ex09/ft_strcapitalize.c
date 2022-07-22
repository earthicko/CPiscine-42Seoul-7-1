/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:21:02 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/18 22:59:37 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	char_is_alphanumeric(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	if ('A' <= c && c <= 'Z')
		return (1);
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}

void	advance_until_alphanumeric(char *str, unsigned int *idx)
{
	while (!(str[*idx] == '\0' || char_is_alphanumeric(str[*idx])))
		(*idx)++;
}

void	capitalize_word(char *str, unsigned int *idx)
{
	unsigned int	idx_in_word;

	idx_in_word = 0;
	while (char_is_alphanumeric(str[*idx]))
	{
		if (idx_in_word == 0)
		{
			if ('a' <= str[*idx] && str[*idx] <= 'z')
				str[*idx] += ('A' - 'a');
		}
		else
		{
			if ('A' <= str[*idx] && str[*idx] <= 'Z')
				str[*idx] += ('a' - 'A');
		}
		(*idx)++;
		idx_in_word++;
	}		
}

char	*ft_strcapitalize(char *str)
{
	unsigned int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		advance_until_alphanumeric(str, &idx);
		capitalize_word(str, &idx);
	}
	return (str);
}
