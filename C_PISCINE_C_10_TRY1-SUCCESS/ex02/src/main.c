/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:09:12 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 22:09:13 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"
#include <stdio.h>

void	handle_line_sep(int n_paths, int n_printed, char *path)
{
	if (n_paths > 1)
	{
		if (n_printed > 0)
			ft_putstr("\n", STDOUT_FILENO);
		print_line_sep(path);
	}
}

void	do_flag_c_tail(int n_paths, char **paths, char *exec_name, int buf_size)
{
	int	i;
	int	n_printed;
	int	fd;

	i = 0;
	n_printed = 0;
	while (i < n_paths)
	{
		errno = 0;
		fd = open(paths[i], O_RDONLY);
		if (fd == -1)
			puterror(paths[i], exec_name);
		else
		{
			handle_line_sep(n_paths, n_printed, paths[i]);
			handle_stream(fd, buf_size);
			n_printed++;
			if (close(fd) != 0)
				puterror(paths[i], exec_name);
		}
		i++;
	}
}

void	do_tail(int n_paths, char **paths, int buf_size, char *exec_name)
{
	if (paths[0] == NULL)
		handle_stream(STDIN_FILENO, buf_size);
	else
		do_flag_c_tail(n_paths, paths, exec_name, buf_size);
}

int	parse_args(int *buf_size, char ***file_paths, int argc, char **argv)
{
	if (argc == 1)
	{
		*file_paths = argv + 1;
		*buf_size = -1;
	}
	else
	{
		if (ft_strcmp(argv[1], "-c") == 0)
		{
			if (argc == 2)
				return (-1);
			*file_paths = argv + 3;
			*buf_size = ft_atoi(argv[2]);
		}
		else
		{
			*file_paths = argv + 1;
			*buf_size = -1;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		buf_size;
	char	**file_paths;
	int		n_paths;

	if (parse_args(&buf_size, &file_paths, argc, argv) == -1)
	{
		print_usage();
		return (0);
	}
	n_paths = 0;
	while (file_paths[n_paths] != NULL)
		n_paths++;
	if (file_paths[0] == NULL)
		handle_stream(STDIN_FILENO, buf_size);
	else
		do_flag_c_tail(n_paths, file_paths, argv[0], buf_size);
	return (0);
}
