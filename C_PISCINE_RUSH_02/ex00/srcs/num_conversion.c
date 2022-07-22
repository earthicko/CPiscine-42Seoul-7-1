/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:57:01 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/01 19:57:03 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ft.h"
#include "../includes/strtools.h"
#include "../includes/io.h"

int	convert_num_to_written_letters(t_entry **dict, char *num)
{
	char	*word;
	int		length;

	if (!is_input_valid_num(num))
	{
		print_error(CODE_GENERAL_ERROR);
		return (-1);
	}
	while ((ft_isspace(*num) || *num == '0') && (ft_strlen(num) > 1))
		num++;
	length = ft_strlen(num);
	word = find_str_from_dict(dict, num, length);
	if (!word)
	{
		print_error(CODE_DICT_ERROR);
		return (-1);
	}
	putstr_without_space(word);
	free(word);
	return (0);
}

char	*find_str_from_dict(t_entry **dict, char *num, int length)
{
	char	*word;
	int		i_digit;

	i_digit = length % 3;
	word = (char *)malloc(sizeof(char));
	if (!word)
		return (NULL);
	word[0] = '\0';
	if (ft_strlen(num) == 1 && num[0] == '0')
		return (ft_append(word, match_str(dict, 0, 0)));
	word = num_to_str(dict, word, num, &i_digit);
	if (i_digit != 0 && length - 3 > 0)
		word = ft_append(word, match_str(dict, length - i_digit, 1));
	num += i_digit;
	length -= i_digit;
	while (*num)
	{
		i_digit = 3;
		word = num_to_str(dict, word, num, &i_digit);
		if (i_digit != 0 && length - 3 != 0)
			word = ft_append(word, match_str(dict, length - 3, 1));
		num += 3;
		length = ft_strlen(num);
	}
	return (word);
}

char	*num_to_str(t_entry **dict, char *str, char *num_all, int *n_fig)
{
	int		num_part;
	char	chunk[4];

	ft_strncpy(chunk, num_all, *n_fig);
	num_part = ft_atoi(chunk);
	if (num_part == 0 || *n_fig == 0)
	{
		*n_fig = 0;
		return (str);
	}
	if (*n_fig == 3 && chunk[0] != '0')
	{
		str = ft_append(str, match_str(dict, chunk[0] - '0', 0));
		str = ft_append(str, match_str(dict, 2, 1));
	}
	if (num_part % 100 >= 20)
	{
		str = ft_append(str,
				match_str(dict, (chunk[*n_fig - 2] - '0') * 10, 0));
		if (chunk[*n_fig - 1] != '0')
			str = ft_append(str, match_str(dict, chunk[*n_fig - 1] - '0', 0));
	}
	if (num_part % 100 < 20 && num_part % 100 != 0)
		str = ft_append(str, match_str(dict, num_part % 100, 0));
	return (str);
}

char	*match_str(t_entry **dict, int target, int type)
{
	int	idx;

	idx = 0;
	while (dict[idx])
	{
		if (dict[idx]->category == type)
		{
			if (type == MULTIPLIER && dict[idx]->multiplier == target)
				return (dict[idx]->name);
			if (type == FIGURE && dict[idx]->n_figures == target)
				return (dict[idx]->name);
		}
		idx++;
	}
	return (NULL);
}
