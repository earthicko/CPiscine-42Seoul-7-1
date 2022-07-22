/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:49:35 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/19 14:07:47 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	idx;

	idx = 0;
	while (!(s1[idx] == '\0' && s2[idx] == '\0') && idx < n)
	{
		if (s1[idx] != s2[idx])
			return ((int)(s1[idx] - s2[idx]));
		idx++;
	}
	return (0);
}
