/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:55:21 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/01 19:55:22 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H
# define MULTIPLIER 0
# define FIGURE 1

typedef struct s_entry
{
	int		category;
	char	*name;
	int		multiplier;
	int		n_figures;
}t_entry;
#endif
