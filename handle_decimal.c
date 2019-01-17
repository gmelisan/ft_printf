/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:24:16 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/17 04:18:01 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_llint	pullarg_decimal(va_list ap, t_uchar length)
{
	if (length == L_HH)
		return (signed char)va_arg(ap, int);
	if (length == L_H)
		return (short int)va_arg(ap, int);
	if (length == L_L)
		return (long int)va_arg(ap, long int);
	if (length == L_LL)
		return (long long int)va_arg(ap, long long int);
	return (int)va_arg(ap, int);
}

int		explicit_precision_zero(t_conversion *conv)
{
	if (conv->prec_set == 1 && conv->precision == 0)
	{
		conv->out = ft_strnew(0);
		return (1);
	}
	return (0);
}

t_uint	count_digits(t_llint n)
{
	t_uint res;

	res = 1;
	while ((n = n / 10))
		res++;
	return (res);
}

t_ullint absolute_value(t_llint n)
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


void	number_to_string(t_llint n, char **str)
{
	t_uint		digits;
	t_ullint	un;
	int			i;

	digits = count_digits(n);
	*str = ft_strnew(digits);
	un = absolute_value(n);
	i = digits - 1;
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
	int		len;
	int		newlen;

	len = ft_strlen(*str);
	if (conv->prec_set)
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

void	handle_decimal(va_list ap, t_conversion *conv)
{
	t_llint		n;
	char		*str;

	n = pullarg_decimal(ap, conv->length);
	if (n == 0 && explicit_precision_zero(conv))
		return ;
	str = NULL;
	number_to_string(n, &str);
	add_zeros(&str, conv);
	add_sign(&str, conv, n);
	add_spaces(&str, conv);
	conv->out = str;
	write(1, conv->out, ft_strlen(conv->out));
}

/* char	*create_number_string(t_conversion *conv, t_llint n) */
/* { */
/* 	char	*str; */
/* 	t_uint	digits; */
/* 	int		len; */
/* 	t_ullint un; */
/* 	int		i; */

/* 	digits = count_digits(n); */
/* 	len = (conv->precision > digits) ? conv->precision : digits; */
/* 	if (conv->flags.plus || conv->flags.space || n < 0) */
/* 		len++; */
/* 	str = ft_strnew(len); */
/* 	ft_memset(str, '0', len - 1); */
/* 	if (n == 0) */
/* 		return (str); */
/* 	un = absolute_value(n); */
/* 	if (n < 0) */
/* 		str[0] = '-'; */
/* 	else if (conv->flags.plus) */
/* 		str[0] = '+'; */
/* 	else if (conv->flags.space && !conv->flags.plus) */
/* 		str[0] = ' '; */
/* 	i = len - 1; */
/* 	while (un) */
/* 	{ */
/* 		str[i] = (un % 10) + '0'; */
/* 		un = un / 10; */
/* 		i--; */
/* 	} */
/* 	return (str); */
/* } */

/* void	handle_decimal(va_list ap, t_conversion *conv) */
/* { */
/* 	t_llint		n; */
/* 	int			len; */
/* 	char		*str; */
/* 	size_t		strsize; */

/* 	n = pullarg_decimal(ap, conv->length); */
/* 	if (n == 0 && explicit_precision_zero(conv)) */
/* 		return ; */
/* 	str = create_number_string(conv, n); */
/* 	strsize = ft_strlen(str); */
/* 	len = (strsize > conv->width) ? strsize : conv->width; */
/* 	if (conv->prec_set && conv->flags.zero) */
/* 		conv->flags.zero = 0; */
/* 	conv->out = ft_strnew(len); */
/* 	if (conv->flags.minus) */
/* 		conv->flags.zero = 0; */
/* 	if (conv->flags.zero) */
/* 		ft_memset(conv->out, '0', len); */
/* 	else */
/* 		ft_memset(conv->out, ' ', len); */
/* 	if (conv->flags.minus) */
/* 		ft_memcpy(conv->out, str, strsize); */
/* 	else */
/* 		ft_memcpy(conv->out + (len - strsize), str, strsize); */
/* 	free(str); */
/* 	write(1, conv->out, len); */
/* } */
