/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 16:05:59 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/28 13:29:12 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

union u_double
{
	long double		val;
	char		data[sizeof(long double)];
};


int		main(void)
{
	setbuf(stdout, NULL);
	/* test_unknown(); */
	/* test_c(); */
	/* test_wc(); */
	/* test_s(); */
	/* test_ws(); */
	test_d();
	/* test_u(); */
	/* test_o(); */
	/* test_x(); */
	/* test_p(); */
	/* test_f(); */
	/* test_bonus(); */
	
	return (0);
}
