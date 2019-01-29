/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:40:26 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/28 17:03:45 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_wstring(va_list ap, t_conversion *conv)
{
	wchar_t		*ws;
	int			wslen;
	

	ws = (wchar_t *)va_arg(ap, wchar_t);
	wslen = ft_strlen((char *)ws);
	
	
}
