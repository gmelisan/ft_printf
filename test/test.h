/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:44:51 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/17 15:52:19 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <unistd.h>

# include "../ft_printf.h"

typedef unsigned long long int t_ullint;

void	test_unknown(void);
void	test_c(void);
void	test_s(void);
void	test_d(void);
void	test_u(void);

#endif
