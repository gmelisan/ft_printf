/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 19:16:27 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/18 21:54:47 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			get_flags(t_conversion *conv, const char *format, int *p_i)
{
	int i;

	i = *p_i;	
	if (format[i] == '#')
		conv->flags.hash = 1;
	if (format[i] == '0')
		conv->flags.zero = 1;
	if (format[i] == '-')
		conv->flags.minus = 1;
	if (format[i] == ' ')
		conv->flags.space = 1;
	if (format[i] == '+')
		conv->flags.plus = 1;
	i++;
	*p_i = i;
}

void			get_width(va_list ap, t_conversion *conv,
							const char *format, int *p_i)
{
	int i;
	int width;

	i = *p_i;
	conv->width = 0;
	if (format[i] == '*')
	{
		width = va_arg(ap, int);
		if (width < 0)
		{
			width = -width;
			conv->flags.minus = 1;
		}
		conv->width = width;
		i++;
	}
	else
		while (ft_isdigit(format[i]))
		{
			conv->width = conv->width * 10 + (format[i] - '0');
			i++;
		}
	*p_i = i;
}

void			get_precision(va_list ap, t_conversion *conv,
								const char *format, int *p_i)
{
	int i;
	int prec;

	i = *p_i;
	if (format[i] == '.')
	{
		i++;
		conv->prec_set = 1;
		conv->precision = 0;
		if (format[i] == '*')
		{
			prec = va_arg(ap, int);
			conv->precision = prec > 0 ? prec : 0;
			i++;
		}
		else
			while (ft_isdigit(format[i]))
			{
				conv->precision = conv->precision * 10 + (format[i] - '0');
				i++;
			}
	}
	*p_i = i;
}

enum e_length	check_length(t_conversion *conv, enum e_length l)
{
	if (l > conv->length)
		return (l);
	return (conv->length);
}

void			get_length(t_conversion *conv, const char *format, int *p_i)
{
	int i;

	i = *p_i;
	if (format[i] == 'L')
		conv->length = check_length(conv, L_LB);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		conv->length = check_length(conv, L_H);
	else if (format[i] == 'h' && format[i + 1] == 'h')
		conv->length = check_length(conv, L_HH);
	else if (format[i] == 'l' && format[i + 1] != 'l')
		conv->length = check_length(conv, L_L);
	else if (format[i] == 'l' && format[i + 1] == 'l')
		conv->length = check_length(conv, L_LL);
	if (conv->length == L_HH || conv->length == L_LL)
		i += 2;
	else if (conv->length == L_LB || conv->length == L_H ||
				conv->length == L_L)
		i += 1;
	*p_i = i;
}

void			get_type(t_conversion *conv, const char *format, int *p_i)
{
	int i;

	i = *p_i;
	conv->type = format[i++];
	*p_i = i;
}
