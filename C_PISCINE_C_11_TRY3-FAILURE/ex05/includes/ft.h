/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:36:02 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/01 16:36:03 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

char	parse_op(char *arg);
void	calculate(int val1, int val2, char op);
int		ft_atoi(char *str);
void	ft_putchar(char c);
void	ft_putstrln(char *str);
void	ft_putnbr(int nb);
int		add(int a, int b);
int		subtract(int a, int b);
int		multiply(int a, int b);
int		divide(int a, int b);
int		modulo(int a, int b);

#endif
