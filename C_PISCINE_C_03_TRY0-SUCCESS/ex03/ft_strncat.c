/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:08:51 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/19 15:27:35 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	idx_dest;
	unsigned int	idx_src;

	idx_dest = 0;
	while (dest[idx_dest] != '\0')
		idx_dest++;
	idx_src = 0;
	while (src[idx_src] != '\0' && idx_src < nb)
	{
		dest[idx_dest] = src[idx_src];
		idx_dest++;
		idx_src++;
	}
	dest[idx_dest] = '\0';
	return (dest);
}
