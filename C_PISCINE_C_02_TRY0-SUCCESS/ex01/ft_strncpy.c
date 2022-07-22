/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 20:26:00 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/16 20:32:53 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	idx;
	int				terminated;

	terminated = 0;
	idx = 0;
	while (idx < n)
	{
		if (terminated == 1)
			dest[idx] = '\0';
		else
		{
			dest[idx] = src[idx];
			if (src[idx] == '\0')
				terminated = 1;
		}
		idx++;
	}
	return (dest);
}
