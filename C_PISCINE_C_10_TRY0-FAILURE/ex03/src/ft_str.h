/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:25:16 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 22:25:17 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

# include "consts.h"
# include <unistd.h>

int		ft_isprint(unsigned char c);
void	ft_putchar(unsigned char c, int fd);
void	ft_putstr(char *str, int fd);
void	ft_putbyte(unsigned char byte, int fd);
int		is_flag_c(char *str);
int		ft_strncmp(char *a, char *b, int n);
char	*ft_strdup(char *src);
char	**create_strarr(int size);

#endif
