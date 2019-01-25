/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 16:01:06 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/25 16:26:38 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		mainloop(va_list ap, const char *format)
{
	int i;
	int len;
	int ret;
	t_conversion	*conv;

	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			conv = get_conversion(ap, format, &i);
			ret = handle_conversion(ap, &conv);
			if (ret == -1)
				return (-1);
			len += ret;
		}
		else
		{
			write(1, &format[i++], 1);
			len++;
		}
	}
	return (len);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret;
	
	va_start(ap, format);
	ret = mainloop(ap, format);
	va_end(ap);
	return (ret);
}
