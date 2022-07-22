/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:47:07 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/26 14:47:09 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*skip_separator(char *start, int *is_sep, int inverted)
{
	if (inverted)
	{
		while (*start != '\0' && !is_sep[(int)(*start)])
			start++;
	}
	else
	{
		while (*start != '\0' && is_sep[(int)(*start)])
			start++;
	}
	return (start);
}

int	count_words(char *str, int *is_sep)
{
	int	n_words;

	n_words = 0;
	while (*str != '\0')
	{
		str = skip_separator(str, is_sep, 0);
		if (*str != '\0')
			n_words++;
		str = skip_separator(str, is_sep, 1);
	}
	return (n_words);
}

int	ft_strlen_sep(char *str, int *is_sep)
{
	int	len;

	len = 0;
	while (str[len] != '\0' && !is_sep[(int)str[len]])
		len++;
	return (len);
}

char	*ft_strdup_word(char *str, int *is_sep)
{
	int		len_word;
	int		idx;
	char	*word;

	idx = 0;
	len_word = ft_strlen_sep(str, is_sep);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (word == NULL)
		return (NULL);
	while (idx < len_word)
	{
		word[idx] = str[idx];
		idx++;
	}
	word[idx] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**strings;
	int		is_sep[128];
	int		idx;
	int		n_words;

	idx = 0;
	while (idx < 128)
		is_sep[idx++] = 0;
	while (*charset)
		is_sep[(int)*charset++] = 1;
	n_words = count_words(str, is_sep);
	idx = 0;
	strings = (char **)malloc(sizeof(char *) * (n_words + 1));
	if (strings == NULL)
		return (NULL);
	while (*str != '\0')
	{
		str = skip_separator(str, is_sep, 0);
		if (*str != '\0')
			strings[idx++] = ft_strdup_word(str, is_sep);
		str = skip_separator(str, is_sep, 1);
	}
	strings[idx] = 0;
	return (strings);
}
