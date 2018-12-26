/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 16:01:06 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/26 21:15:12 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list			ap;
	int				i;
	t_conversion	*conv;
	int				ret;

	va_start(ap, format);
	ret = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			conv = get_conversion(ap, format, &i);
			handle_conversion(ap, &conv);
			write(1, conv->out, conv->outlen);
			ret += conv->outlen;
		}
		else
		{
			write(1, &format[i++], 1);
			ret++;
		}
	}
	va_end(ap);
	return (ret);
}
