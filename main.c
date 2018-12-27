/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 16:05:59 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/27 17:19:06 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int a;
	int b[2];

	a = -2341;
	/* printf("[%010.20l%]\n", 10, 7, 5); */
	/* b[0] = ft_printf("My number is [%d]!\n", a); */
	/* b[1] = printf("My number is [%d]!\n", a); */

	/* ft_printf("res1 = %d\n", b[0]); */
	/* printf("{%d}\n", ft_printf("res2 = %d\n", b[1])); */
	printf("[%0.0d]\n", 0);
	printf("[%0.1d]\n", 0);
	printf("[%1.0d]\n", 0);
	printf("[%1.1d]\n", 0);
	printf("[%0d]\n", 0);
	printf("[%1d]\n", 0);
	printf("[%01d]\n", 0);
	
	return (0);
}
