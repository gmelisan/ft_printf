/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:49:03 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/17 17:54:46 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_u_run(char *format, t_ullint n)
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

void	test_u(void)
{
	printf("============================\n");
	printf("========== test_u ==========\n");
	printf("============================\n");
	printf("[printf] [ft_printf]\n");
	printf("ret ft_ret\n\n");

	test_u_run("%u", 21);
	test_u_run("%u", -21);
	test_u_run("%20.15u", -21);
	test_u_run("%020u", -21);
	test_u_run("%-20.15u", -111111);
	test_u_run("% u", -111111);
	test_u_run("% 0.0u", -111);
	test_u_run("%U", 4294967296);
}
