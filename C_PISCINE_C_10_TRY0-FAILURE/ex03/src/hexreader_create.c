/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexreader_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:25:24 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 22:25:26 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"
#include "ft_str.h"

t_hexreader	*free_reader(t_hexreader *reader)
{
	int	i;

	if (reader->exec_name)
		free(reader->exec_name);
	if (reader->buffer)
		free(reader->buffer);
	if (reader->buffer_prev)
		free(reader->buffer_prev);
	if (reader->name_files)
	{
		i = 0;
		while (i < reader->n_files)
		{
			if (reader->name_files[i])
				free(reader->name_files[i]);
			i++;
		}
	}
	free(reader);
	return (NULL);
}

t_hexreader	*alloc_reader(void)
{
	t_hexreader	*reader;

	reader = (t_hexreader *)malloc(sizeof(t_hexreader));
	if (!reader)
		return (NULL);
	reader->exec_name = NULL;
	reader->buffer = NULL;
	reader->buffer_prev = NULL;
	reader->canonical_ascii = 0;
	reader->line_repeated = 0;
	reader->n_line_printed = 0;
	reader->n_byte_printed = 0;
	reader->all_files_error = 1;
	reader->n_files = 0;
	reader->name_files = NULL;
	return (reader);
}

t_hexreader	*init_reader(int argc, char **argv)
{
	t_hexreader	*reader;

	reader = alloc_reader();
	if (!reader)
		return (NULL);
	reader->exec_name = ft_strdup(argv[0]);
	if (!reader->exec_name)
		return (free_reader(reader));
	reader->buffer_prev = (char *)malloc(sizeof(char) * N_BYTES + 1);
	if (!reader->buffer_prev)
		return (free_reader(reader));
	reader->buffer = (char *)malloc(sizeof(char) * N_BYTES + 1);
	if (!reader->buffer)
		return (free_reader(reader));
	if (parse_args(argc, argv, reader) == 0)
		return (reader);
	else
		return (free_reader(reader));
}
