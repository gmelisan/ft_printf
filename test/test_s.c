/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:49:39 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/17 18:26:56 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_s_run(char *format, char *str)
{
	int r1, r2;

	ft_putstr(format);
	printf("\n[");
	r1 = printf(format, str);
	printf("] [");
	r2 = ft_printf(format, str);
	printf("]\n%d %d\n\n", r1, r2);
}

void	test_s(void)
{
	printf("============================\n");
	printf("========== test_s ==========\n");
	printf("============================\n");
	printf("*note: all flags except of '-' have undefined behavior\n");
	printf("precision cuts the string\n\n");
	printf("[printf] [ft_printf]\n");
	printf("ret ft_ret\n\n");

	test_s_run("%s", "Hello, world!");
	test_s_run("%010s", "hello");
	test_s_run("%20s", "darkness");
	test_s_run("%5.4s", "darkness");
	test_s_run("%-10s", "my");
	test_s_run("%3.10s", "old");
	test_s_run("%.10 3s", "old");
	test_s_run("%1.100s", "friend");
	test_s_run("%0.0s", "friend");
	test_s_run("%0.s", "friend");
	test_s_run("%s", "");
	test_s_run("%10w...%s", "unknown_test");
	test_s_run("%s", NULL);
	test_s_run("%10s", NULL);

	test_s_run("%10s", NULL);
	test_s_run("%10.-3s", "hello");
	
}
