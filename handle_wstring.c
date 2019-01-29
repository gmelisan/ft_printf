/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:40:26 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/29 19:35:36 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	build_wstring(char *str, wchar_t *ws, t_conversion *conv)
{
	t_uint	i;
	t_uint	j;
	char	s[5];
	int		len;

	i = 0;
	j = 0;
	while (ws[i])
	{
		ft_bzero(s, 5);
		len = ft_wctomb_utf8(s, ws[i]);
		j += len;
		if (j > conv->precision && conv->prec_set)
			break ;
		ft_strncpy(&str[j - len], s, len);
		i++;
	}
}

void	handle_wstring(va_list ap, t_conversion *conv)
{
	wchar_t		*ws;
	int			wslen;
	char		*str;
	size_t		strsize;
	int			len;

	ws = (wchar_t *)va_arg(ap, wchar_t *);
	if (!ws)
		str = ft_strdup("(null)");
	else
	{
		wslen = ft_strlen((char *)ws);
		str = ft_strnew(wslen);
		build_wstring(str, ws, conv);
	}
	strsize = ft_strlen(str);
	len = conv->width > strsize ? conv->width : strsize;
	conv->out = prepare_out(conv, len);
	if (conv->flags.minus)
		ft_memcpy(conv->out, str, strsize);
	else
		ft_memcpy(conv->out + (len - strsize), str, strsize);
	conv->outlen = len;
	ft_strdel(&str);
}
