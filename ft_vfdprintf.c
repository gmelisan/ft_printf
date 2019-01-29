/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfdprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:41:57 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/28 14:42:48 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_symbol_percent(int fd, const char *format, va_list ap, int *i)
{
	t_conversion	*conv;
	int				len;

	conv = get_conversion(ap, format, i);
	len = handle_conversion(ap, conv);
	if (len != -1)
		write(fd, conv->out, len);
	clear_conversion(&conv);
	return (len);
}

static int	handle_symbol_openbrace(int fd, const char *format, int *i)
{
	int		len;

	len = 1;
	write(fd, format, *i);
	return (len);
}

static int	handle_symbol(int fd, const char *format, va_list ap, int *i)
{
	int		len;

	len = 1;
	if (format[*i] == '%')
		len = handle_symbol_percent(fd, format, ap, i);
	else if (format[*i] == '{')
		len = handle_symbol_openbrace(fd, format, i);
	else
		write(fd, &format[(*i)++], len);
	return (len);
}

int			ft_vfdprintf(int fd, const char *format, va_list ap)
{
	int		ret;
	int		len;
	int		i;

	ret = 0;
	i = 0;
	while (format[i])
	{
		ret = handle_symbol(fd, format, ap, &i);
		if (ret == -1)
			return (ret);
		len += ret;
	}
	return (len);
}
