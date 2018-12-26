/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:24:19 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/26 21:43:20 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_conversion	*get_conversion(va_list ap, const char *format, int *i)
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
