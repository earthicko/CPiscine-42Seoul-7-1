/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:52:46 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/01 14:52:47 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_str(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

int	listlen(char **list)
{
	int	len;

	len = 0;
	while (list[len])
		len++;
	return (len);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	len;
	int	base;
	int	cmp_lim;

	len = listlen(tab);
	cmp_lim = len - 1;
	while (0 < cmp_lim)
	{
		base = 0;
		while (base < cmp_lim)
		{
			if (cmp(tab[base], tab[base + 1]) > 0)
				swap_str(&tab[base], &tab[base + 1]);
			base++;
		}
		cmp_lim--;
	}
}
