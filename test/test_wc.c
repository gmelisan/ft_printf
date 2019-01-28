/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_wc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:25:59 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/28 09:33:17 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <wchar.h>
#include <locale.h>

void	test_wc_run(char *format, wint_t c)
{
	int r1, r2;

	r1 = 0;
	r2 = 0;
	ft_putstr(format);
	printf("\n[");
	r1 = printf(format, c);
	printf("] [");
	r2 = ft_printf(format, c);
	printf("]\n%d %d\n\n", r1, r2);
}

void	test_wc(void)
{
	setlocale(LC_ALL, "");
	printf("============================\n");
	printf("========== test_wc ==========\n");
	printf("============================\n");
	printf("[printf] [ft_printf]\n");
	printf("ret ft_ret\n\n");

	wint_t c = 254;
	test_wc_run("%hhc", c);
	test_wc_run("%hc", c);
	test_wc_run("%c", c);
	test_wc_run("%lc", c);
	test_wc_run("%llc", c);
	test_wc_run("%jc", c);
	test_wc_run("%Lc", c);
	printf("\n");
}
