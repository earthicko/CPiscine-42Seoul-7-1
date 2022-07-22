/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:07:19 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 22:07:21 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <libgen.h>
#include "io.h"

void	ft_putstr(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

void	puterror(char *file, char *name_exec)
{
	ft_putstr(basename(name_exec), STDERR_FILENO);
	ft_putstr(": ", STDERR_FILENO);
	ft_putstr(file, STDERR_FILENO);
	ft_putstr(": ", STDERR_FILENO);
	ft_putstr(strerror(errno), STDERR_FILENO);
	ft_putstr("\n", STDERR_FILENO);
	errno = 0;
}

void	putfile(int fd, char *file, char *name_exec)
{
	unsigned char	buf[BUF_SIZE];
	long			n_read;

	while (1)
	{
		n_read = read(fd, buf, BUF_SIZE);
		if (errno)
		{
			puterror(file, name_exec);
			return ;
		}
		if (n_read == 0)
			return ;
		write(STDOUT_FILENO, buf, n_read);
	}
}
