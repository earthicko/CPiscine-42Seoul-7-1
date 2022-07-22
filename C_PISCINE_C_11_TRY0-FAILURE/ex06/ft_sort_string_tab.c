/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:52:35 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/01 14:52:36 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	listlen(char **list)
{
	int	len;

	len = 0;
	while (list[len])
		len++;
	return (len);
}

void	ft_sort_string_tab(char **tab)
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
			if (ft_strcmp(tab[base], tab[base + 1]) > 0)
				swap_str(&tab[base], &tab[base + 1]);
			base++;
		}
		cmp_lim--;
	}
}
