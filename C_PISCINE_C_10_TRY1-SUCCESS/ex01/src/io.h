/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:07:22 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 22:07:24 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H
# include <unistd.h>
# include <fcntl.h>
# define BUF_SIZE 1

void	ft_putstr(char *str, int fd);
void	puterror(char *file, char *name_exec);
void	putfile(int fd, char *file, char *name_exec);
#endif
