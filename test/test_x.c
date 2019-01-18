/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 21:19:42 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/18 21:56:47 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_x_run(char *format, t_llint n)
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

void	test_x(void)
{
	printf("============================\n");
	printf("========== test_x ==========\n");
	printf("============================\n");
	printf("[printf] [ft_printf]\n");
	printf("ret ft_ret\n\n");

	test_x_run("%x", 0);
	test_x_run("%x", 42);
	test_x_run("%#x", 42);
	test_x_run("%10.5x", 42);
	test_x_run("%#10.5x", 42);
	test_x_run("%#10.5X", 42);

	/* test_x_run("%#-10.5x", 42); */
	/* test_x_run("%-10.5x", 42); */
	/* test_x_run("%05x", 42); */
	/* test_x_run("%05.0x", 42); */
	/* test_x_run("%05.0x", 0); */
	/* test_x_run("%#05.0x", 0); */
	/* test_x_run("%01.0x", 0); */
	/* test_x_run("%#02.0x", 0); */
	/* test_x_run("%#X", 520); */
	/* test_x_run("%#10.5X", 520); */
	
}
