/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unknown.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 20:40:39 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/16 22:06:28 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_unknown_run(char *format, char *str)
{
	int r1, r2;

	ft_putstr(format);
	printf("\n[");
	r1 = printf(format, str);
	printf("] [");
	r2 = ft_printf(format, str);
	printf("]\n%d %d\n\n", r1, r2);
}

void	test_unknown(void)
{
	printf("============================\n");
	printf("========== test_%% ==========\n");
	printf("============================\n");
	printf("*note: any unknown type is like %%\n");
	printf("[printf] [ft_printf]\n");
	printf("ret ft_ret\n\n");

	test_unknown_run("%%", "");
	test_unknown_run("Le percento:%4%", "");
	test_unknown_run("Le percento:%-4%", "");
	
	test_unknown_run("%10w", "");
	test_unknown_run("%04k", "");
	test_unknown_run("%-4k", "");
}
