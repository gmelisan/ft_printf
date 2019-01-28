/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 21:17:44 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/26 19:45:54 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	clear(t_conversion **conv)
{
	int ret;

	ret = (*conv)->outlen;
	ft_strdel(&(*conv)->out);
	ft_memdel((void **)conv);
	return (ret);
}

static int	is_integer(t_uchar c)
{
	if (c == 'd' || c == 'D' || c == 'i' ||
		c == 'u' || c == 'U' ||
		c == 'o' || c == 'O' ||
		c == 'x' || c == 'X' ||
		c == 'b' || c == 'p')
		return (1);
	return (0);
}

int			handle_conversion(va_list ap, t_conversion **conv)
{
	if (!(*conv))
		return (0);
	if (is_integer((*conv)->type))
		handle_integer(ap, *conv);
	else if (ft_tolower((*conv)->type) == 'f' ||
				ft_tolower((*conv)->type) == 'e')
		handle_float(ap, *conv);
	else if (ft_tolower((*conv)->type) == 'c')
		handle_char(ap, *conv);
	else if (ft_tolower((*conv)->type) == 's')
		handle_string(ap, *conv);
	else
		handle_unknown(*conv);
	return (clear(conv));
}
