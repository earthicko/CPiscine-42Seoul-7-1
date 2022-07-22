/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:51:56 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/01 14:51:57 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	counter;

	counter = 0;
	while (*tab != 0)
	{
		if (f(*tab))
			counter++;
		tab++;
	}
	return (counter);
}
