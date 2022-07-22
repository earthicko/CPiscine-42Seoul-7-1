/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:57:55 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/19 15:27:14 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	idx_dest;
	int	idx_src;

	idx_dest = 0;
	while (dest[idx_dest] != '\0')
		idx_dest++;
	idx_src = 0;
	while (src[idx_src] != '\0')
	{
		dest[idx_dest] = src[idx_src];
		idx_dest++;
		idx_src++;
	}
	dest[idx_dest] = '\0';
	return (dest);
}
