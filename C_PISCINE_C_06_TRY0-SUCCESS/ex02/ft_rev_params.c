/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:05:06 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/25 12:10:10 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstrln(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	i_arg;

	i_arg = argc - 1;
	while (0 < i_arg)
	{
		ft_putstrln(argv[i_arg]);
		i_arg--;
	}
	return (0);
}
