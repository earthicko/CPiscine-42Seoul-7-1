/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:57:06 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/01 19:57:08 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft.h"
#include "../includes/strtools.h"
#include "../includes/errors.h"

void	print_error(int code)
{
	if (code == CODE_GENERAL_ERROR)
		write(1, GENERAL_ERROR_STR, L_GENERAL_ERROR_STR);
	else if (code == CODE_DICT_ERROR)
		write(1, DICT_ERROR_STR, L_DICT_ERROR_STR);
}

void	remove_last_space(char *str)
{
	while (*str)
		str++;
	str -= 1;
	if (*str == ' ')
		*str = '\n';
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	putstr_without_space(char *word)
{
	remove_last_space(word);
	ft_putstr(word);
}
