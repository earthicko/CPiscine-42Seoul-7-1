/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:56:12 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/01 19:56:15 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# include "dict.h"

void	free_entries_until(t_entry **dict, int lim);
void	free_dict(t_entry **dict);
void	free_arr_str(char **arr_str);

int		get_file_size(char *path);
char	*read_file_to_str(char *path, int input_len);
t_entry	**build_dict(char *path);
t_entry	**create_dict(char **lines);

int		check_entry(char *str);
int		create_entries(char **lines, t_entry **dict);
int		parse_line(t_entry *dict, char **split_line);
char	*fill_left(char *str);
char	*fill_right(char *str);

char	*match_str(t_entry **dict, int target, int type);
char	*num_to_str(t_entry **dict, char *out, char *num, int *n);
int		is_input_valid_num(char *str);
char	*find_str_from_dict(t_entry **dict, char *num, int length);
int		convert_num_to_written_letters(t_entry **dict, char *num);

#endif
