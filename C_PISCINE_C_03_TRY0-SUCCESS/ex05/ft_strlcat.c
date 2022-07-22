/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:23:27 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/19 17:43:56 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef unsigned int	t_uint;

t_uint	ft_strlen(char *str)
{
	t_uint	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	t_uint	len_src;
	t_uint	len_dest;
	t_uint	i_src;
	t_uint	i_dest;

	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	i_src = 0;
	i_dest = len_dest;
	if (size > len_dest)
	{
		while (i_dest < size - 1 && src[i_src] != '\0')
		{
			dest[i_dest] = src[i_src];
			i_src++;
			i_dest++;
		}
		dest[i_dest] = '\0';
	}
	if (size < len_dest)
		return (len_src + size);
	else
		return (len_src + len_dest);
}
