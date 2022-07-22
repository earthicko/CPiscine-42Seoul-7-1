/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_entry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:56:40 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/01 19:56:43 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ft.h"
#include "../includes/dict.h"
#include "../includes/strtools.h"

int	create_entries(char **lines, t_entry **dict)
{
	int		index;
	char	**split_line;

	index = 0;
	while (*lines)
	{
		split_line = ft_split_by_first_char(*lines, ':');
		if (!split_line)
			return (-1);
		dict[index] = (t_entry *)malloc(sizeof(t_entry));
		if (!dict[index])
		{
			free_entries_until(dict, index - 1);
			return (-1);
		}
		if (parse_line(dict[index], split_line) < 0)
		{
			free_entries_until(dict, index - 1);
			return (-1);
		}
		index++;
		lines++;
	}
	dict[index] = NULL;
	return (0);
}

int	parse_line(t_entry *entry, char **split_line)
{
	char	*num;

	num = fill_left(split_line[0]);
	if (!num)
		return (-1);
	if (ft_strlen(num) <= 2)
	{
		entry->category = MULTIPLIER;
		entry->multiplier = ft_atoi(num);
	}
	else
	{
		entry->category = FIGURE;
		entry->n_figures = ft_strlen(num) - 1;
	}
	entry->name = fill_right(split_line[1]);
	if (!entry->name)
	{
		free(num);
		return (-1);
	}
	free_arr_str(split_line);
	free(num);
	return (0);
}

char	*fill_left(char *str)
{
	int		count;
	char	*number;
	int		idx;

	count = 0;
	while (*str == ' ')
		str++;
	if (*str == '+')
		str++;
	idx = 0;
	while (is_number(str[idx++]))
		count++;
	number = (char *)malloc(sizeof(char) * (count + 1));
	if (!number)
		return (NULL);
	idx = 0;
	while (is_number(str[idx]))
	{
		number[idx] = str[idx];
		idx++;
	}
	number[idx] = '\0';
	return (number);
}

char	*fill_right(char *str)
{
	int		count;
	char	*word;
	int		idx;
	char	*copy_from;

	count = 0;
	idx = 0;
	while (str[idx] == ' ')
		idx++;
	copy_from = str + idx;
	while (str[idx++])
		count++;
	word = (char *)malloc(sizeof(char) * (count + 1));
	if (!word)
		return (NULL);
	ft_strcpy(word, copy_from);
	return (word);
}
