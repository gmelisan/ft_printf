/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 21:17:44 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/27 18:41:41 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	clear(t_conversion **conv)
{
	int res;

	res = ft_strlen((*conv)->out);
	free(out);
	ft_memdel(conv);
}

int			handle_conversion(va_list ap, t_conversion **conv)
{
	if ((*conv)->type == '%')
		handle_percent(ap, *conv);
	else if ((*conv)->type == 'd' ||  (*conv)->type == 'i')
		handle_decimal(ap, *conv);
	else if ((*conv)->type == 'u')
		handle_unsigned(ap, *conv);
	else if ((*conv)->type == 'o')
		handle_octal(ap, *conv);
	else if ((*conv)->type == 'x' || (*conv)->type == 'X')
		handle_hexadecimal(ap, *conv);
	else if ((*conv)->type == 'f' || (*conv)->type == 'F')
		handle_float(ap, *conv);
	else if ((*conv)->type == 'c')
		handle_char(ap, *conv);
	else if ((*conv)->type == 's')
		handle_string(ap, *conv);
	else if ((*conv)->type == 'p')
		handle_pointer(ap, *conv);
	return (clear(conv));
}
