/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:25:30 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 22:25:41 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"
#include "ft_str.h"
#include "consts.h"

int	main(int argc, char **argv)
{
	t_hexreader	*reader;

	reader = init_reader(argc, argv);
	if (reader->name_files[0] == NULL)
	{
		if (hexdump_stdin(reader) != 0)
		{
			free_reader(reader);
			return (0);
		}
	}
	else
	{
		if (hexdump_files(reader) != 0)
		{
			free_reader(reader);
			return (0);
		}
	}
	print_last_line(reader);
	free(reader->buffer);
	return (0);
}
