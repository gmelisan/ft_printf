/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:47:31 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/26 18:44:04 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_llint	pullarg_integer(va_list ap, t_uchar length)
{
	if (length == L_HH)
		return (signed char)va_arg(ap, int);
	if (length == L_H)
		return (short int)va_arg(ap, int);
	if (length == L_L)
		return (long int)va_arg(ap, long int);
	if (length == L_LL)
		return (long long int)va_arg(ap, long long int);
	if (length == L_J)
		return (__intmax_t)va_arg(ap, __intmax_t);
	if (length == L_Z)
		return (long int)va_arg(ap, long int);
	return (int)va_arg(ap, int);
}

t_ullint	pullarg_unsigned(va_list ap, t_uchar length)
{
	if (length == L_HH)
		return (unsigned char)va_arg(ap, int);
	if (length == L_H)
		return (unsigned short int)va_arg(ap, int);
	if (length == L_L)
		return (unsigned long int)va_arg(ap, long int);
	if (length == L_LL)
		return (unsigned long long int)va_arg(ap, long long int);
	if (length == L_J)
		return (__uintmax_t)va_arg(ap, __uintmax_t);
	if (length == L_Z)
		return (size_t)va_arg(ap, size_t);
	return (unsigned int)va_arg(ap, int);
}

int		is_longtype(char c)
{
	if (c == 'D' || c == 'U' || c == 'O' || c  == 'p')
		return (1);
	return (0);
}

void	handle_integer(va_list ap, t_conversion *conv)
{
	t_llint		n;

	if (is_longtype(conv->type) && conv->length != L_LL)
	{
		conv->length = L_L;
		conv->type = ft_tolower(conv->type);
	}
	if (conv->type == 'd' || conv->type == 'i')
		n = pullarg_integer(ap, conv->length);
	else
		n = pullarg_unsigned(ap, conv->length);
	convert_integer(conv, n);
	conv->outlen = ft_strlen(conv->out);
	write(1, conv->out, conv->outlen);
}
