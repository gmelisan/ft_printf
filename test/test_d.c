/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 20:48:53 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/28 21:29:47 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_d_run(char *format, long long int n)
{
	char f[100];
	int r1;
	int r2 = 0;

	bzero(f, 100);
	f[0] = '%';
	memcpy(f + 1, format, strlen(format));
	printf(f, n);
	printf(", %lld\n[", n);
	r1 = printf(format, n);
	printf("] [");
	/* r2 = ft_printf(format, n); */
	printf("]\n%d %d\n\n", r1, r2);
}

void	test_d(void)
{
	printf("============================\n");
	printf("========== test_d ==========\n");
	printf("============================\n");
	printf("*note: # is ignored\n"); 
	printf("precision = minimum of digits that must appear\n");
    printf("(pad with 0)\n");
	printf("When 0 is printed with explicit precision 0,\n");
	printf("the output is empty\n\n");
	printf("[printf] [ft_printf]\n");
	printf("ret ft_ret\n\n");

	test_d_run("%d", 42);
	test_d_run("% d", 42);
	test_d_run("%+d", 42);
	test_d_run("%5d", 42);	
	test_d_run("% 5d", 42);
	test_d_run("%+5d", 42);
	test_d_run("%-5d", 42);
	test_d_run("% -5d", 42);
	test_d_run("%05d", 42);
	test_d_run("%0+5d", 42);
	test_d_run("%0+ 5d", 42);
	test_d_run("%5.0d", 42);
	test_d_run("%5.2d", 42);
	test_d_run("%5.5d", 42);
	test_d_run("%10.5d", 42);
	test_d_run("%+10.5d", 42);
	test_d_run("%-10.5d", 42);
	test_d_run("%+-10.5d", 42);
	test_d_run("% -10.5d", 42);
	test_d_run("%+-10.5d", 0);
	test_d_run("%-10.5d", 0);
	test_d_run("% 1.0d", 0);
	test_d_run("%hhd", 257);
	test_d_run("%hd", 65537);
	test_d_run("%d", 4294967297);
	test_d_run("%ld", 4294967298);
	test_d_run("%lld", 1234567890123456789);
	test_d_run("%lld", 12345678901234567890);	
}
