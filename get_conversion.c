/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:24:19 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/16 20:22:08 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_conversion	*get_conversion_old(va_list ap, const char *format, int *i)
{
	t_conversion *conv;

	*i = *i + 1;
	conv = ft_memalloc(sizeof(*conv));
	get_flags(conv, format, i);
	get_width(ap, conv, format, i);
	get_precision(ap, conv, format, i);
	get_length(conv, format, i);
	get_type(conv, format, i);
	return (conv);
}

int				is_flag(char c)
{
	if (c == '#' || c == '0' || c == '+' || c == '-' || c == ' ')
		return (1);
	return (0);
}

int				is_length(char c)
{
	if (c == 'l' || c == 'h' || c == 'L')
		return (1);
	return (0);

}

int				is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
		c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f' ||
		c == '%')
		return (1);
	return (0);
}

t_conversion	*get_conversion(va_list ap, const char *format, int *i)
{
	t_conversion *conv;

	*i = *i + 1;
	conv = ft_memalloc(sizeof(*conv));
	while (1)
	{
		if (is_flag(format[*i]))
			get_flags(conv, format, i);
		else if (ft_isdigit(format[*i]) || format[*i] == '*')
			get_width(ap, conv, format, i);
		else if (format[*i] == '.')
			get_precision(ap, conv, format, i);
		else if (is_length(format[*i]))
			get_length(conv, format, i);
		else
			break ;
	}
	conv->type = format[*i];
	*i = *i + 1;
	return (conv);
}
