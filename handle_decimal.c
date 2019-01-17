/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:24:16 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/17 16:50:46 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_uint		count_digits(t_ullint n)
{
	t_uint res;

	res = 1;
	while ((n = n / 10))
		res++;
	return (res);
}

t_ullint	absolute_value(t_llint n)
{
	t_ullint un;

	if (n >= 0)
		un = (t_ullint)n;
	else
	{
		n = (n + 1) * (-1);
		un = (t_ullint)n;
		un++;
	}
	return (un);
}


void	number_to_string(t_llint n, char **str, int flag_unsigned)
{
	t_uint		digits;
	int			i;
	t_ullint	un;

	un = flag_unsigned ? (t_ullint)n : absolute_value(n);
	digits = count_digits(un);
	*str = ft_strnew(digits);
	i = digits - 1;
	if (un == 0)
		(*str)[i] = '0';
	while (un)
	{
		(*str)[i] = (un % 10) + '0';
		un = un / 10;
		i--;
	}
}

void	add_zeros(char **str, t_conversion *conv)
{
	char	*newstr;
	size_t	len;
	size_t	newlen;

	len = ft_strlen(*str);
	if (conv->flags.minus || conv->prec_set)
		conv->flags.zero = 0;
	if (conv->flags.zero && conv->width > len)
		newlen = conv->width - 1;
	else
		newlen = conv->precision;
	if (newlen > len)
	{
		newstr = ft_strnew(newlen);
		ft_memset(newstr, '0', newlen);
		ft_memcpy(newstr + (newlen - len), *str, len);
		ft_strdel(str);
		*str = newstr;
	}
}

void	add_sign(char **str, t_conversion *conv, t_llint n)
{
	char *newstr;

	newstr = NULL;
	if (n < 0)
		newstr = ft_strjoin("-", *str);
	else if (conv->flags.plus)
		newstr = ft_strjoin("+", *str);
	else if (conv->flags.space)
		newstr = ft_strjoin(" ", *str);
	if (n < 0 || conv->flags.plus || conv->flags.space)
	{
		ft_strdel(str);
		*str = newstr;
	}
}

void	add_spaces(char **str, t_conversion *conv)
{
	char	*newstr;
	int		len;
	int		newlen;

	len = ft_strlen(*str);
	newlen = conv->width;
	if (newlen > len)
	{
		newstr = prepare_out(conv, newlen);
		if (conv->flags.minus)
			ft_memcpy(newstr, *str, len);
		else
			ft_memcpy(newstr + (newlen - len), *str, len);
		ft_strdel(str);
		*str = newstr;
	}
}

void	handle_decimal(t_conversion *conv, t_llint n, int flag_unsigned)
{
	char	*str;

	str = NULL;
	if (n == 0 && conv->prec_set && conv->precision == 0)
		str = ft_strnew(0);
	else
		number_to_string(n, &str, flag_unsigned);
	add_zeros(&str, conv);
	if (!flag_unsigned)
		add_sign(&str, conv, n);
	add_spaces(&str, conv);
	conv->out = str;
	write(1, conv->out, ft_strlen(conv->out));
}
