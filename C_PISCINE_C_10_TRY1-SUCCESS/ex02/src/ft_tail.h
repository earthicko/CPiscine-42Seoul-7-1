/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:09:05 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 22:09:06 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H
# define ERROR_ARG_C "tail: option requires an argument -- c\n"
# define ERROR_USAGE "usage: tail [-F | -f | -r] "
# define ERROR_USAGE2 "[-q] [-b # | -c # | -n #] [file ...]\n"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <libgen.h>
# include <errno.h>
# include <string.h>

typedef struct s_string {
	int		n;
	int		cap;
	char	*items;
}	t_string;

t_string	*string_init(int cap_);
t_string	*string_del(t_string *del);
int			string_append(t_string *str, char c);
int			ft_atoi_until(char *str, int nchars);
void		puterror(char *file, char *exec_name);
void		print_line_sep(char *name);
void		print_usage(void);
void		pipe_until_end(int fd);
int			ft_atoi(char *str);
void		ft_putstr(char *str, int fd);
int			ft_strcmp(char *s1, char *s2);
t_string	*read_file_to_str(int fd);
void		handle_stream(int fd, int buf_size);

#endif
