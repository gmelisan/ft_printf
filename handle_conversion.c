/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 21:17:44 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/26 21:46:26 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_conversion(va_list ap, t_conversion **pp_conv)
{
	int arg;
	t_conversion *conv;

	conv = *pp_conv;
	if (conv->type == '%')
		write(1, &conv->type, 1);
	else if (conv->type == 'd')
	{
		arg = va_arg(ap, int);
		conv->out = ft_itoa(arg);
		conv->outlen = ft_strlen(conv->out);
	}
	*pp_conv = conv;
}
