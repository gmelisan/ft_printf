/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:44:15 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/24 16:08:13 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_f_run(char *format, double n)
{
	int r1, r2;

	ft_putstr(format);
	printf("\n[");
	r1 = printf(format, n);
	printf("] [");
	r2 = ft_printf(format, n);
	printf("]\n%d %d\n\n", r1, r2);
}

void	test_f_run_long(char *format, long double n)
{
	int r1, r2;

	ft_putstr(format);
	printf("\n[");
	r1 = printf(format, n);
	printf("] [");
	r2 = ft_printf(format, n);
	printf("]\n%d %d\n\n", r1, r2);
}

void	test_f(void)
{
	printf("============================\n");
	printf("========== test_f ==========\n");
	printf("============================\n");

	long double n = 122.99999999999990000;

	test_f_run_long("%.12Lf", n);
	test_f_run_long("%.14Lf", n);
	test_f_run_long("%.14Lf", n);
	test_f_run_long("%.2Lf", 0);
	test_f_run_long("%#.Lf", 0);
	test_f_run_long("%#.Lf", 10.0);
	test_f_run_long("%.Lf", 3.0);
	test_f_run_long("%.2Lf", 2.955);
	test_f_run_long("%07.3Lf", 2.3456);
	
	test_f_run("%f", -1.42);
	test_f_run("%f", 0);
	test_f_run("%.f", 0);
	test_f_run("%#.f", 0);
	
	test_f_run("%10.2f", 10.4222);
	test_f_run("%010.2f", 10.4222);
	test_f_run("%10.2f", 10.4222);
	test_f_run("%-10.2f", 10.4222);
	test_f_run("%#-10.f", 0);
	test_f_run("%#+10.f", 32);
	test_f_run("%+-10.0f", 42);

	test_f_run("%f", NAN);
	test_f_run("%f", 1.0/0);
	test_f_run("%f", -1.0/0);

	test_f_run("%F", NAN);
	test_f_run("%F", 1.0/0);
	test_f_run("%F", -1.0/0);
}
