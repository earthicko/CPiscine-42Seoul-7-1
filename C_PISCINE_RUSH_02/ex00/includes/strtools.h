/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtools.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:56:25 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/01 19:56:27 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRTOOLS_H
# define STRTOOLS_H

int		is_number(char c);
int		ft_isprint(char c);
int		ft_isspace(char c);
int		is_char_in_str(char *str, char c);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		in_charset(char c, char *charset);
int		count_word(char *str, char *charset);
char	**ft_split(char *str, char *charset);
char	**ft_split_by_first_char(char *str, char c);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
char	*ft_append(char *init_pos, char *src);
char	*ft_strcat_space(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, int size);
int		listlen(char **strs);
#endif
