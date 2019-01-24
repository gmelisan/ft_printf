/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:26:37 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/24 09:25:19 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	round_digit(int *n, int next)
{
	if (next >= 5)
		*n = *n + 1;
}

char	*double2str(long double n, int prec)
{
	char			*str;
	int				i;
	long double		sub;
	int				digits;
	int				d;
	int				len;

	digits = 1;
	while (n >= 10)
	{
		digits++;
		n = n / 10;		
	}
	len = digits + prec + 1;
	str = ft_strnew(len);
	d = (int)n;
	i = 0;
	str[i++] = d + '0';
	sub = (long double)d;
	while (i < len)
	{
		if (i == digits)
			str[i++] = '.';
		n = n * 10;
		sub = sub * 10;
		d = n - sub;
		sub += d;
		str[i++] = d + '0';
	}
	return (str);	
}

void	handle_float(va_list ap, t_conversion *conv)
{
	long double		n;
	char			*str;

	if (conv->precision == 0 && conv->prec_set == 0)
		conv->precision = 6;
	if (conv->length == L_LB)
		n = (long double)va_arg(ap, long double);
	else
		n = (double)va_arg(ap, double);
	str = double2str(n, conv->precision);
	ft_putstr(str);
}
