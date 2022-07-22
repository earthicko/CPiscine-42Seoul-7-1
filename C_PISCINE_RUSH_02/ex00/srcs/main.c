/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:56:50 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/01 19:57:00 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/io.h"
#include "../includes/ft.h"

void	set_input_path(char **input, char **path, int argc, char *argv[])
{
	if (argc == 2)
	{
		*path = "numbers.dict";
		*input = argv[1];
	}
	if (argc == 3)
	{
		*path = argv[1];
		*input = argv[2];
	}
}

int	main(int argc, char **argv)
{
	char	*path;
	char	*input;
	t_entry	**dict;

	if (argc < 2 || argc > 3)
	{
		print_error(CODE_GENERAL_ERROR);
		return (0);
	}
	set_input_path(&input, &path, argc, argv);
	dict = build_dict(path);
	if (!dict)
	{
		print_error(CODE_DICT_ERROR);
		return (0);
	}
	convert_num_to_written_letters(dict, input);
	free_dict(dict);
	return (0);
}
