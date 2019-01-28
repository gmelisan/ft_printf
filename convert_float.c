/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:57:16 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/28 09:27:19 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 
** 123.456 (double) -> 1.234566 (double)
*/

static void			normalize_f(long double *n, int *digits)
{
	*digits = 1;
	while (*n >= 10)
	{
		*n = *n / 10;
		(*digits)++;
	}
}

/* 
** 123.456 (double) -> 1.234566 (double)
** 0.00123 (double) -> 1.23 (double)
*/

static void			normalize_e(long double *n, int *digits)
{
	if (*n >= 1)
		normalize_f(n, digits);
	else
	{
		*digits = -1;
		while (*n < 1)
		{
			*n = *n * 10;
			(*digits)++;
		}
		*digits = -(*digits);
	}
}

/*
** 1.23456 (double) -> 123.456 (char *)
*/

static void			shift_point(long double n, char *str,
									int len, int digits)
{
	int				i;
	long double		sub;
	int				d;

	i = 0;
	d = (int)n;
	str[i++] = d + '0';
	sub = (long double)d;
	while (i < len)
	{
		if (i == digits)
			str[i++] = '.';
		n = n * 10;
		sub = sub * 10;
		d = n - sub;
		sub += d;
		str[i++] = d + '0';
	}
}

/* 
** 1.23456 (double) -> 1.23456 (char *)
*/

static void			shift_point_1(long double n, char *str, int prec)
{
	int				i;
	long double		sub;
	int				d;

	i = 0;
	d = (int)n;
	str[i++] = d + '0';
	str[i++] = '.';
	sub = (long double)d;
	while (i < prec + 2 + 1)
	{
		n = n * 10;
		sub = sub * 10;
		d = n - sub;
		sub += d;
		str[i++] = d + '0';
	}
}

/*
** One day I'll get rid of all these reallocs, but not today
*/

static int			add_e(char **str, int len, char e, int exp)
{
	ft_realloc((void **)str, len, len + 5);
	(*str)[len + 0] = e;
	(*str)[len + 1] = (exp >= 0 ? '+' : '-');
	exp = (exp > 0 ? exp : -exp);
	(*str)[len + 2] = exp / 10 + '0';
	(*str)[len + 3] = exp % 10 + '0';
	(*str)[len + 4] = '\0';
	return (len + 4);
}

/*
** prec = 2 
** 123.456 -> 123.46
** 123.496 -> 123.50
** 123.999 -> 124.00
*/

static void			round(char *str, int i, int carry)
{
	int prev;

	prev = i - 1;
	if (str[prev] == '.')
		prev--;
	if (prev < 0)
		return ;
	if (str[i] >= '5' || carry)
	{
		if (str[prev] == '9')
		{
			str[prev] = '0';
			round(str, prev, 1);
		}
		else
			str[prev]++;
	}
}

/* 
** n = 123.456
** len = 3(digits) + 1(dot) + precision + 1(for rounding)
*/

static void			number_to_string_f(t_conversion *conv, long double n)
{
	int		digits;
	int		len;

	digits = 0;
	if (n < 0)
		n = -n;
	normalize_f(&n , &digits);
	if (conv->prec_set && conv->precision == 0)
		len = digits + (conv->flags.hash ? 1 : 0) + 1;
	else 
		len = digits + 1 + conv->precision + 1;
	conv->out = ft_strnew(len);
	shift_point(n, conv->out, len, digits);
	round(conv->out, len - 1, 0);
	conv->out[len - 1] = '\0';
}

static void			number_to_string_e(t_conversion *conv, long double n)
{
	int		digits;
	int		len;

	digits = 0;
	if (n < 0)
		n = -n;
	normalize_e(&n , &digits);
	if (conv->prec_set && conv->precision == 0)
		len = 1 + (conv->flags.hash ? 1 : 0) + 1;
	else 
		len = 1 + 1 + conv->precision + 1;
	conv->out = ft_strnew(len);
	shift_point_1(n, conv->out, conv->precision);
	round(conv->out, len - 1, 0);
	add_e(&(conv->out), len - 1, conv->type, digits - 1);
}

static void			add_zeros(t_conversion *conv)
{
	char	*newstr;
	size_t	len;
	size_t	newlen;

	len = ft_strlen(conv->out);
	newlen = 0;
	if (conv->flags.minus)
		conv->flags.zero = 0;
	if (conv->flags.zero && conv->width > len)
		newlen = conv->width - 1;
	if (newlen > len)
	{
		newstr = ft_strnew(newlen);
		ft_memset(newstr, '0', newlen);
		ft_memcpy(newstr + (newlen - len), conv->out, len);
		ft_strdel(&(conv->out));
		conv->out = newstr;
	}
}

static void			add_sign(t_conversion *conv, long double n)
{
	char *newstr;

	newstr = NULL;
	if (n < 0)
		newstr = ft_strjoin("-", conv->out);
	else if (conv->flags.plus)
		newstr = ft_strjoin("+", conv->out);
	else if (conv->flags.space)
		newstr = ft_strjoin(" ", conv->out);
	if (newstr)
	{
		ft_strdel(&(conv->out));
		conv->out = newstr;
	}
}

static void			add_spaces(t_conversion *conv)
{
	char	*newstr;
	int		len;
	int		newlen;

	len = ft_strlen(conv->out);
	newlen = conv->width;
	if (newlen > len)
	{
		newstr = prepare_out(conv, newlen);
		if (conv->flags.minus)
			ft_memcpy(newstr, conv->out, len);
		else
			ft_memcpy(newstr + (newlen - len), conv->out, len);
		ft_strdel(&(conv->out));
		conv->out = newstr;
	}
}

void				convert_float(t_conversion *conv, long double n)
{
	if (ft_tolower(conv->type) == 'f')
		number_to_string_f(conv, n);
	else if (ft_tolower(conv->type) == 'e')
		number_to_string_e(conv, n);
	add_zeros(conv);
	add_sign(conv, n);
	add_spaces(conv);
}
