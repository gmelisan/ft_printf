/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_wc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:25:59 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/24 16:48:41 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <wchar.h>

void	test_wc_run(char *format, wint_t c)
{
	int r1, r2;

	r2 = 0;
	ft_putstr(format);
	printf("\n[");
	r1 = printf(format, c);
	printf("] [");
	//r2 = ft_printf(format, c);
	printf("]\n%d %d\n\n", r1, r2);
}

void	test_wc(void)
{
	printf("============================\n");
	printf("========== test_wc ==========\n");
	printf("============================\n");
	printf("[printf] [ft_printf]\n");
	printf("ret ft_ret\n\n");

	printf("%C\n", L'ÊM-^ZM-^V');
	printf("%.4S", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
}
