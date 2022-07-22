/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:03:52 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 22:03:53 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(STDOUT_FILENO, str + i, 1);
		i++;
	}
}

int	ft_display_file(char *name)
{
	char	buf;
	int		fd;
	int		n_read;

	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot read file.\n");
		return (-1);
	}
	while (1)
	{
		n_read = read(fd, &buf, 1);
		if (n_read <= 0)
			break ;
		write(STDOUT_FILENO, &buf, n_read);
	}
	close(fd);
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		ft_putstr("File name missing.\n");
	else if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else
		ft_display_file(argv[1]);
	return (0);
}
