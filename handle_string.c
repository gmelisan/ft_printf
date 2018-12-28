/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:27:24 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/28 20:38:26 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_string(va_list ap, t_conversion *conv)
{
	char	*str;
	int		len;
	size_t	strsize;

	str = va_arg(ap, char *);
	strsize = ft_strlen(str);
	if (conv->precision > strsize)
		conv->precision = strsize;
	if (conv->precision < strsize && conv->prec_set)
		strsize = conv->precision;
	len = conv->width > strsize ? conv->width : strsize;
	conv->out = ft_strnew(len);
	if (conv->flags.minus)
		conv->flags.zero = 0;
	if (conv->flags.zero)
		ft_memset(conv->out, '0', len);
	else
		ft_memset(conv->out, ' ', len);
	if (conv->flags.minus)
		ft_memcpy(conv->out, str, strsize);
	else
		ft_memcpy(conv->out + (len - strsize), str, strsize);
	write(1, conv->out, len);
}
