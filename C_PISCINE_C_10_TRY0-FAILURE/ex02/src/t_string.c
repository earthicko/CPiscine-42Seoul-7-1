/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:09:14 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 22:09:15 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:05:28 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 10:05:34 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

t_string	*string_init(int new_cap)
{
	t_string	*str;

	str = (t_string *)malloc(sizeof(t_string));
	if (!str)
		return (NULL);
	str->n = 0;
	str->cap = new_cap;
	str->items = (char *)malloc(sizeof(char) * new_cap);
	if (!str->items)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

t_string	*string_del(t_string *del)
{
	free(del->items);
	free(del);
	return (NULL);
}

int	string_realloc(t_string *str, int new_cap)
{
	char	*temp;
	int		i;

	if (str->cap >= new_cap)
		return (0);
	temp = str->items;
	str->items = (char *)malloc(sizeof(char) * new_cap);
	if (!str->items)
	{
		free(temp);
		free(str);
		return (-1);
	}
	i = 0;
	while (i < str->cap)
	{
		str->items[i] = temp[i];
		i++;
	}
	free(temp);
	str->cap = new_cap;
	return (0);
}

int	string_append(t_string *str, char new)
{
	if (str->n == str->cap)
	{
		if (string_realloc(str, str->cap * 2) == -1)
		{
			free(str);
			return (-1);
		}
	}
	str->items[str->n] = new;
	str->n++;
	return (0);
}
