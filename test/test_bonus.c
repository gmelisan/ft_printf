/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 21:57:08 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/29 17:48:12 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_bonus_b_run(char *format, t_llint n)
{
	int r;

	ft_putstr(format);
	printf(", %lld\n[", n);
	r = ft_printf(format, n);
	printf("]\n%d\n\n", r);
}

void	test_bonus_e_run(char *format, long double n)
{
	int r1, r2;

	ft_putstr(format);
	printf("\n[");
	r1 = printf(format, n);
	printf("] [");
	r2 = ft_printf(format, n);
	printf("]\n%d %d\n\n", r1, r2);
}

void	test_bonus(void)
{
	printf("============================\n");
	printf("========= test_bunus =======\n");
	printf("============================\n\n");

	test_bonus_b_run("%b", 666);
	test_bonus_b_run("%14.11#b", 666);

	long double ld = 0.00005;
	test_bonus_e_run("%.2Le", ld);
	ft_printf("{black}black {red}red\n");
	ft_printf("{green}green {yellow}yellow\n");
	ft_printf("{blue}blue {purple}purple\n");
	ft_printf("{cyan}cyan {eoc}eoc\n");
}
