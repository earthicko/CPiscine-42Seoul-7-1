/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:13:55 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/19 17:59:25 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i_base;
	unsigned int	i_offset;

	if (to_find[0] == '\0')
		return (str);
	i_base = 0;
	while (str[i_base] != '\0')
	{
		i_offset = 0;
		while (to_find[i_offset] != '\0')
		{
			if (str[i_base + i_offset] != to_find[i_offset])
				break ;
			i_offset++;
		}
		if (to_find[i_offset] == '\0')
			return (str + i_base);
		i_base++;
	}
	return (0);
}
