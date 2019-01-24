/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:44:51 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/24 16:03:51 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>

# include "../ft_printf.h"

typedef unsigned long long int t_ullint;

void	test_unknown(void);
void	test_c(void);
void	test_s(void);
void	test_d(void);
void	test_u(void);
void	test_o(void);
void	test_x(void);
void	test_bonus(void);
void	test_p(void);
void	test_f(void);


#endif
