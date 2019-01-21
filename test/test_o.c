/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 21:09:42 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/21 16:00:28 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_o_run(char *format, t_llint n)
{
	int r1;
	int r2 = 0;

	ft_putstr(format);
	printf(", %lld\n[", n);
	r1 = printf(format, n);
	printf("] [");
	r2 = ft_printf(format, n);
	printf("]\n%d %d\n\n", r1, r2);
}

void	test_o(void)
{
	printf("============================\n");
	printf("========== test_o ==========\n");
	printf("============================\n");
	printf("[printf] [ft_printf]\n");
	printf("ret ft_ret\n\n");

	test_o_run("%o", 0);
	test_o_run("%o", 42);
	test_o_run("%#o", 42);
	test_o_run("%#o", 0);
	test_o_run("%10.5o", 42);
	test_o_run("%#10.5o", 42);
	test_o_run("%#-10.5o", 42);
	test_o_run("%-10.5o", 42);
	test_o_run("%05o", 42);
	test_o_run("%05.0o", 42);
	test_o_run("%05.0o", 0);
	test_o_run("%#05.0o", 0);
	test_o_run("%01.0o", 0);
	test_o_run("%#02.0o", 0);
}
