/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:09:16 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 22:09:24 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	print_error_msg(char *file, char *exec_name)
{
	ft_putstr(basename(exec_name), STDERR_FILENO);
	ft_putstr(": ", STDERR_FILENO);
	ft_putstr(file, STDERR_FILENO);
	ft_putstr(": ", STDERR_FILENO);
	ft_putstr(strerror(errno), STDERR_FILENO);
	ft_putstr("\n", STDERR_FILENO);
}

void	print_usage(void)
{
	ft_putstr(ERROR_ARG_C, STDOUT_FILENO);
	ft_putstr(ERROR_USAGE, STDOUT_FILENO);
	ft_putstr(ERROR_USAGE2, STDOUT_FILENO);
}

void	print_line_sep(char *name)
{
	ft_putstr("==> ", STDOUT_FILENO);
	ft_putstr(name, STDOUT_FILENO);
	ft_putstr(" <==\n", STDOUT_FILENO);
}
