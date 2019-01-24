/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:44:15 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/24 09:25:37 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "test.h"

void	test_f_run(char *format, long double n)
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

	long double n = 23765.4821;

	/* int count = 0; */
	/* while (n > 10) */
	/* { */
	/* 	count++; */
	/* 	n = n / 10; */
	/* 	printf("%Lf\n", n); */
	/* 	//test_f_run("%Lf", n); */
	/* } */
	/* while (--count) */
	/* { */
	/* 	n = n * 10; */
	/* 	printf("%Lf\n", n); */
	/* } */
	/* long int a; */
	/* a = (long int)n; */
	ft_printf("%Lf\n", n);
	
	
}
