/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:04:23 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 10:17:02 by seonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_STRING_H
# define T_STRING_H
# include <stdlib.h>

typedef struct s_string {
	int		n;
	int		cap;
	char	*items;
}	t_string;

t_string	*string_init(int cap_);
t_string	*string_del(t_string *del);
int			string_append(t_string *str, char c);
int			ft_atoi_until(char *str, int nchars);

#endif
