/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:47:31 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/17 19:11:39 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 
		add to libft: tolower, toupper
*/

int		ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

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
	return (unsigned int)va_arg(ap, int);
}

void	handle_integer(va_list ap, t_conversion *conv)
{
	t_llint		n;

	if (conv->type == 'D' || conv->type == 'U' || conv->type == 'O')
	{
		conv->type = ft_tolower(conv->type);
		if (conv->length != L_LL)
			conv->length = L_L;
	}
	if (conv->type == 'd' || conv->type == 'i')
		n = pullarg_integer(ap, conv->length);
	else
		n = pullarg_unsigned(ap, conv->length);
	conv->out = create_integer_out(conv, n);
	write(1, conv->out, ft_strlen(conv->out));
}
