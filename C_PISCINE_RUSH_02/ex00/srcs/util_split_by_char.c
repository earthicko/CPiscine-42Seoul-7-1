/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_split_by_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:57:29 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/01 19:57:30 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/strtools.h"

char	**ft_alloc_split_by_first_char(int l_prev, int l_after)
{
	char	**split;

	split = (char **)malloc(sizeof(char *) * 3);
	if (!split)
		return (NULL);
	split[0] = (char *)malloc(sizeof(char) * (l_prev + 1));
	if (!split[0])
	{
		free(split);
		return (NULL);
	}
	split[1] = (char *)malloc(sizeof(char) * (l_after + 1));
	if (!split[1])
	{
		free(split[0]);
		free(split);
		return (NULL);
	}
	split[2] = NULL;
	return (split);
}

char	**ft_split_by_first_char(char *str, char c)
{
	int		pos;
	int		len_prev;
	int		len_after;
	char	**split;

	pos = is_char_in_str(str, c);
	if (pos == -1)
		return (NULL);
	len_prev = pos;
	len_after = ft_strlen(str) - pos - 1;
	split = ft_alloc_split_by_first_char(len_prev, len_after);
	if (!split)
		return (NULL);
	ft_strncpy(split[0], str, len_prev);
	ft_strncpy(split[1], str + len_prev + 1, len_after);
	return (split);
}
