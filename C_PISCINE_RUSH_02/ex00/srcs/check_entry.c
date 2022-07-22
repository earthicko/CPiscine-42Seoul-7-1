/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:56:28 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/01 19:56:30 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"
#include "../includes/strtools.h"

int	check_left(char *left_part)
{
	if (!is_number(*left_part))
		return (0);
	while (is_number(*left_part))
		left_part++;
	while (*left_part)
	{
		if (*left_part != ' ')
			return (0);
		left_part++;
	}
	return (1);
}

int	check_right(char *right_part)
{
	while (*right_part == ' ')
		right_part++;
	if (*right_part == '\0')
		return (0);
	while (*right_part)
	{
		if (!ft_isprint(*right_part))
			return (0);
		right_part++;
	}
	return (1);
}

int	check_entry(char *line)
{
	char	**split_line;

	if (is_char_in_str(line, ':') == -1)
		return (0);
	split_line = ft_split_by_first_char(line, ':');
	if (!split_line)
		return (0);
	if (!(check_left(split_line[0]) && check_right(split_line[1])))
	{
		free_arr_str(split_line);
		return (0);
	}
	free_arr_str(split_line);
	return (1);
}
