/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:47:14 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/21 15:05:42 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_c_run(char *format, char c)
{
	int r1, r2;

	ft_putstr(format);
	printf("\n[");
	r1 = printf(format, c);
	printf("] [");
	r2 = ft_printf(format, c);
	printf("]\n%d %d\n\n", r1, r2);
}

void	test_c(void)
{
	printf("============================\n");
	printf("========== test_c ==========\n");
	printf("============================\n");
	printf("*note: all flags except of '-' have undefined behavior\n");
	printf("precision has undefined behavior\n\n");
	printf("[printf] [ft_printf]\n");
	printf("ret ft_ret\n\n");

	test_c_run("%c", 'a');
	test_c_run("%4c", 'b');
	test_c_run("%04c", 'b');
	test_c_run("%-5c", 'c');
	test_c_run("%c", 0);
	test_c_run("%1c", 0);
	test_c_run("%3c", 0);
	test_c_run("%-3c", 0);
	test_c_run("%.c", 'a');
}
