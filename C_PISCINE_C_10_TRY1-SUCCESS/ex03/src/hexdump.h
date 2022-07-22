/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:25:20 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 22:25:21 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEXDUMP_H
# define HEXDUMP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>
# include "consts.h"

typedef struct s_hexreader
{
	char	*exec_name;
	char	*buffer;
	char	*buffer_prev;
	int		canonical_ascii;
	int		line_repeated;
	int		n_line_printed;
	int		n_byte_printed;
	int		printed_atleast_once;
	int		all_files_error;
	int		n_files;
	char	**name_files;
}			t_hexreader;

int			parse_args(int argc, char **argv, t_hexreader *reader);
t_hexreader	*init_reader(int argc, char **argv);
t_hexreader	*free_reader(t_hexreader *reader);
void		print_linenum(t_hexreader *reader, int is_leftover);
void		print_bytes_in_hex(t_hexreader *reader);
void		print_bytes_in_ascii(t_hexreader *reader);
void		puterror(char *file, char *exec_name);
int			is_flag_c(char *str);
int			print_line(t_hexreader *reader);
void		print_last_line(t_hexreader *reader);
int			hexdump_loop(int fd, int i_file, t_hexreader *reader);
int			hexdump_files(t_hexreader *reader);

#endif
