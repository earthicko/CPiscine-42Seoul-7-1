/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:08:00 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/25 12:17:11 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	idx;

	idx = 0;
	while (s1[idx] == s2[idx] && !(s1[idx] == '\0' && s2[idx] == '\0'))
		idx++;
	return ((int)(s1[idx] - s2[idx]));
}

void	swap_str(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	sort_str(char **arr_str, int n_str)
{
	int	base;
	int	cmp_lim;

	cmp_lim = n_str - 1;
	while (0 < cmp_lim)
	{
		base = 0;
		while (base < cmp_lim)
		{
			if (ft_strcmp(arr_str[base], arr_str[base + 1]) > 0)
				swap_str(&arr_str[base], &arr_str[base + 1]);
			base++;
		}
		cmp_lim--;
	}
}

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

	sort_str(argv + 1, argc - 1);
	i_arg = 1;
	while (i_arg < argc)
	{
		ft_putstrln(argv[i_arg]);
		i_arg++;
	}
	return (0);
}
