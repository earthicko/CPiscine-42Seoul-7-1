/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexreader_argparse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:25:22 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 22:25:24 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"
#include "ft_str.h"

int	is_flag_c(char *str)
{
	if (str[0] == '-' && str[1] == 'C' && str[2] == '\0')
		return (1);
	return (0);
}

int	search_flag_c(int argc, char **argv)
{
	if (argc > 1 && is_flag_c(argv[1]))
		return (1);
	return (0);
}

int	copy_file_names(int argc, char **argv, int flag_idx, t_hexreader *reader)
{
	int	i_file;
	int	i;

	i = 1;
	i_file = 0;
	while (i < argc)
	{
		if (i != flag_idx)
		{
			reader->name_files[i_file] = argv[i];
			i_file++;
		}
		i++;
	}
	return (0);
}

int	parse_args(int argc, char **argv, t_hexreader *reader)
{
	int	flag_idx;

	reader->canonical_ascii = 0;
	reader->n_files = argc - 1;
	flag_idx = search_flag_c(argc, argv);
	if (flag_idx)
	{
		reader->canonical_ascii = 1;
		reader->n_files = argc - 2;
	}
	reader->name_files = create_strarr(reader->n_files);
	if (!reader->name_files)
		return (-1);
	if (copy_file_names(argc, argv, flag_idx, reader) != 0)
		return (-1);
	return (0);
}
