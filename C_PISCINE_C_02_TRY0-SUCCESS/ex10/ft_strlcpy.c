/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 13:01:29 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/17 13:17:16 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *src)
{
	unsigned int	len;

	len = 0;
	while (src[len] != '\0')
		len++;
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	idx;

	src_len = ft_strlen(src);
	if (size > 0)
	{
		idx = 0;
		while (src[idx] != '\0' && idx < size - 1)
		{
			dest[idx] = src[idx];
			idx++;
		}
		dest[idx] = '\0';
	}
	return (src_len);
}
