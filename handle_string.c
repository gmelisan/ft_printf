/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:27:24 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/25 18:13:15 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_null_string(t_conversion *conv)
{
	char *str;
	int len;
	size_t strsize;

	str = ft_strdup("(null)");
	strsize = ft_strlen(str);
	if (conv->prec_set && conv->precision < strsize)
		strsize = conv->precision;
	len = conv->width > strsize ? conv->width : strsize;
	conv->out = prepare_out(conv, len);
	if (conv->flags.minus)
		ft_memcpy(conv->out, str ,strsize);
	else
		ft_memcpy(conv->out + (len - strsize), str, strsize);
	conv->outlen = len;
	write(1, conv->out, conv->outlen);
	ft_strdel(&str);
}

void	handle_string(va_list ap, t_conversion *conv)
{
	char	*str;
	int		len;
	size_t	strsize;

	str = va_arg(ap, char *);
	if (!str)
	{
		handle_null_string(conv);
		return ;
	}
	strsize = ft_strlen(str);
	if (conv->prec_set && conv->precision < strsize)
		strsize = conv->precision;
	len = conv->width > strsize ? conv->width : strsize;
	conv->out = prepare_out(conv, len);
	if (conv->flags.minus)
		ft_memcpy(conv->out, str ,strsize);
	else
		ft_memcpy(conv->out + (len - strsize), str, strsize);
	conv->outlen = len;
	write(1, conv->out, conv->outlen);
}
