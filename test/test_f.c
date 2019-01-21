/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:44:15 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/21 17:20:24 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "test.h"

void	test_f_run(char *format, double n)
{
	char f[100];
	int r1;
	int r2 = 0;

	bzero(f, 100);
	f[0] = '%';
	memcpy(f + 1, format, strlen(format));
	printf(f, n);
	printf(", %f\n[", n);
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

	double n = 42.21;

	test_f_run("%.20f", n);
	
	
}
