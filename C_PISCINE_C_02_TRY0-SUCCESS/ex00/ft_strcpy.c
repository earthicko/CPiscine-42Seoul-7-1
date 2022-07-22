/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 20:22:00 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/16 20:24:50 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	idx;

	idx = 0;
	while (1)
	{
		dest[idx] = src[idx];
		if (src[idx] == '\0')
			break ;
		idx++;
	}
	return (dest);
}
