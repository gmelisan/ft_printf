/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:26:56 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/16 23:46:43 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prepare_out(t_conversion *conv, int len)
{
	char *out;

	out = ft_strnew(len);
	if (conv->flags.minus)
		conv->flags.zero = 0;
	if (conv->flags.zero)
		ft_memset(out, '0', len);
	else
		ft_memset(out, ' ', len);
	return (out);
}

void	handle_char(va_list ap, t_conversion *conv)
{
	int len;
	char c;

	len = conv->width ? conv->width : 1;
	c = (char)va_arg(ap, int);
	conv->out = prepare_out(conv, len);
	if (conv->flags.minus)
		conv->out[0] = c;
	else
		conv->out[len - 1] = c;
	write(1, conv->out, len);
	if (!c)
		ft_memset(conv->out, '0', len);
}
