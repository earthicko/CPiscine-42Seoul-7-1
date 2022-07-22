/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:56:21 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/01 19:56:23 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# include <unistd.h>
# include "errors.h"
# define IO_H

void	print_error(int code);
void	putstr_without_space(char *str);
void	remove_last_space(char *str);
void	ft_putstr(char *word);
#endif
