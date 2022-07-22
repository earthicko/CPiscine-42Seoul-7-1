/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:56:45 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/01 19:56:49 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ft.h"

void	free_entry(t_entry *entry)
{
	if (entry->name)
		free(entry->name);
	free(entry);
}

void	free_entries_until(t_entry **dict, int lim)
{
	int	idx;

	idx = 0;
	while (dict[idx] && idx < lim)
	{
		free_entry(dict[idx]);
		idx++;
	}
}

void	free_dict(t_entry **dict)
{
	int	idx;

	idx = 0;
	while (dict[idx])
	{
		free_entry(dict[idx]);
		idx++;
	}
	free(dict);
}

void	free_arr_str(char **arr_str)
{
	int	idx;

	idx = 0;
	while (arr_str[idx])
		free(arr_str[idx++]);
	free(arr_str);
}
