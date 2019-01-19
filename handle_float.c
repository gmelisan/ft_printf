/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:26:37 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/19 00:19:33 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ten_power(int p)
{
	int res;
	int i;

	res = 1;
	i = -1;
	while (++i < p)
		res *= 10;
	return (res);
}

void	handle_float(va_list ap, t_conversion *conv)
{
	long double	n;
	long double	tmp;
	t_llint		integer;
	t_llint		real;

	if (conv->length == L_LB)
		n = (long double)va_arg(ap, long double);
	else
		n = (double)va_arg(ap, double);
	integer = (t_llint)n;
	tmp = n - integer;
	tmp *= ten_power(conv->precision);
	real = (t_llint)tmp;
	ft_printf("%lld.%lld", integer, real);
}
