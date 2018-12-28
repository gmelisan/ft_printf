/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:26:56 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/28 18:59:09 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_char(va_list ap, t_conversion *conv)
{
	int len;
	char c;

	len = conv->width ? conv->width : 1;
	c = va_arg(ap, int);
	conv->out = ft_strnew(len);
	if (conv->flags.minus)
		conv->flags.zero = 0;
	if (conv->flags.zero)
		ft_memset(conv->out, '0', len);
	else
		ft_memset(conv->out, ' ', len);
	if (conv->flags.minus)
		conv->out[0] = c;
	else
		conv->out[len - 1] = c;
	write(1, conv->out, len);
}
