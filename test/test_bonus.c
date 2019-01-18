/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 21:57:08 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/18 22:06:24 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_bonus_run(char *format, t_llint n)
{
	int r;

	ft_putstr(format);
	printf(", %lld\n[", n);
	r = ft_printf(format, n);
	printf("]\n%d\n\n", r);
}

void	test_bonus(void)
{
	printf("============================\n");
	printf("========= test_bunus =======\n");
	printf("============================\n\n");

	test_bonus_run("%b", 666);
	test_bonus_run("%14.11#b", 666);
}
