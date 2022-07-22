/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:57:14 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/02 20:57:15 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	counter;
	int	idx;

	counter = 0;
	idx = 0;
	while (idx < length)
	{
		if (f(tab[idx]))
			counter++;
		idx++;
	}
	return (counter);
}
