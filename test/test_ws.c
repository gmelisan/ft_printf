/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ws.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 09:58:25 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/29 20:05:57 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <locale.h>

void	test_ws_run(char *format, wchar_t *s)
{
	int r1, r2;

	r1 = 0;
	r2 = 0;
	ft_putstr(format);
	printf("\n[");
	r1 = printf(format, s);
	printf("] [");
	r2 = ft_printf(format, s);
	printf("]\n%d %d\n\n", r1, r2);
}

void	test_ws(void)
{
	setlocale(LC_ALL, "en_US.UTF-8");
	printf("============================\n");
	printf("========== test_ws ==========\n");
	printf("============================\n");
	printf("[printf] [ft_printf]\n");
	printf("ret ft_ret\n\n");

	wchar_t s[] = {254, 437, 254, 0};

	test_ws_run("%S", L"我是一只猫。");
	/* test_ws_run("%010.10S", s); */
}
