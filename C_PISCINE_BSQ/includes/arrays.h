/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:03:43 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 10:03:53 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAYS_H
# define ARRAYS_H

int		**alloc_int_array_2(int rows, int cols);
int		delete_int_array_2(int **arr, int n_rows);
char	**alloc_char_array_2(int rows, int cols);
char	delete_char_array_2(char **arr, int n_rows);

#endif
