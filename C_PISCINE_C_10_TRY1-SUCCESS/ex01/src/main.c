/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:07:25 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 22:07:29 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

int	main(int argc, char *argv[])
{
	int	fd;
	int	i;

	if (argc == 1)
		putfile(STDIN_FILENO, NULL, argv[0]);
	else
	{
		i = 1;
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd == -1)
				puterror(argv[i], argv[0]);
			else
			{
				putfile(fd, argv[i], argv[0]);
				close(fd);
			}
			i++;
		}
	}
	return (0);
}
