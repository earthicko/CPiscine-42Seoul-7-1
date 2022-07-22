/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:05:14 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 10:05:16 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "../includes/io.h"
#include "../includes/solve.h"
#include "../includes/draw.h"

int	open_file_solve_print(int fd)
{
	t_map		*map;
	t_charmap	*charmap;

	map = create_map(fd);
	if (!map)
	{
		print_map_error();
		return (-1);
	}
	if (solve(map) == -1)
		return (-1);
	charmap = draw(map);
	if (!charmap)
	{
		delete_map(map);
		return (-1);
	}
	print_map(charmap);
	delete_map(map);
	delete_charmap(charmap);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	fd;

	if (argc == 0)
		return (0);
	if (argc == 1)
		open_file_solve_print(STDIN_FILENO);
	else
	{
		i = 1;
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd == -1)
				print_map_error();
			else
				open_file_solve_print(fd);
			i++;
		}
	}
	return (0);
}
