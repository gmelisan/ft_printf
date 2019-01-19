/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 22:29:17 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/18 22:49:45 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "test.h"

void	test_p_run(char *format, void *n)
{
	int r1;
	int r2 = 0;

	ft_putstr(format);
	printf(", %p\n[", n);
	r1 = printf(format, n);
	printf("] [");
	r2 = ft_printf(format, n);
	printf("]\n%d %d\n\n", r1, r2);
}

void	test_p(void)
{
	char *str = "Hello";

	printf("============================\n");
	printf("========== test_p ==========\n");
	printf("============================\n");
	printf("[printf] [ft_printf]\n");
	printf("ret ft_ret\n\n");

	test_p_run("%p", &str[0]);
	test_p_run("%20p", &str[0]);
	test_p_run("%020p", &str[0]);
	test_p_run("%-20p", &str[0]);
	test_p_run("%20.16p", &str[0]);
	test_p_run("%0.0p", &str[0]);
	test_p_run("%p", 0);
	test_p_run("%.0p", 0);
	test_p_run("%020p", 0);
	test_p_run("%-20p", 0);
	test_p_run("%20.16p", 0);
	test_p_run("%#10.10p", 0);
}
