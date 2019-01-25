/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:26:37 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/25 14:52:31 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_non_valid(t_conversion *conv, long double n)
{
	if (n != n)
		conv->out = ft_strdup(conv->type == 'F' ? "NAN" : "nan");
	else if (n == 1.0 / 0)
		conv->out = ft_strdup(conv->type == 'F' ? "INF" : "inf");
	else if (n == -1.0 / 0)
		conv->out = ft_strdup(conv->type == 'F' ? "-INF" : "-inf");
	else
		return (1);
	return (0);	
}

void	handle_float(va_list ap, t_conversion *conv)
{
	long double		n;

	if (conv->precision == 0 && conv->prec_set == 0)
		conv->precision = 6;
	if (conv->length == L_LB)
		n = (long double)va_arg(ap, long double);
	else
		n = (double)va_arg(ap, double);
	if (check_non_valid(conv, n))
		convert_float(conv, n);
	conv->outlen = ft_strlen(conv->out);
	write(1, conv->out, conv->outlen);
}
