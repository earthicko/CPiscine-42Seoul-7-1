/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:25:27 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 22:25:27 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"
#include "ft_str.h"

void	ft_putstr(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], fd);
		i++;
	}
}

void	puterror(char *file, char *exec_name)
{
	ft_putstr(basename(exec_name), STDERR_FILENO);
	ft_putstr(": ", STDERR_FILENO);
	ft_putstr(file, STDERR_FILENO);
	ft_putstr(": ", STDERR_FILENO);
	ft_putstr(strerror(errno), STDERR_FILENO);
	ft_putchar('\n', STDERR_FILENO);
	errno = 0;
}
