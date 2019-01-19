/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_integer_out.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:24:16 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/18 23:26:24 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_uint		count_digits(t_ullint n, int base)
{
	t_uint res;

	res = 1;
	while ((n = n / base))
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

char	int2char(int n, int flag_bigsym)
{
	if (n > 9)
		return (n - 10 + (flag_bigsym ? 'A' : 'a'));
	return (n + '0');
}


int		get_base(char c)
{
	if (c == 'x' || c == 'X' || c == 'p')
		return (16);
	if (c == 'o' || c == 'O')
		return (8);
	if (c == 'b')
		return (2);
	return (10);
}

char	*number_to_string(t_llint n, t_conversion *conv, int flag_unsigned)
{
	t_uint		digits;
	int			i;
	t_ullint	un;
	int			base;
	char		*str;

	un = flag_unsigned ? (t_ullint)n : absolute_value(n);
	base = get_base(conv->type);
	digits = count_digits(un, base);
	str = ft_strnew(digits);
	i = digits - 1;
	if (un == 0)
		str[i] = '0';
	while (un)
	{
		str[i] = int2char(un % base, (conv->type == 'X' ? 1 : 0));
		un = un / base;
		i--;
	}
	return (str);
}

int		get_sign_space(t_conversion *conv, t_llint n)
{
	if (get_base(conv->type) == 16 && n != 0)
		return (2);
	return (1);
}

void	add_zeros(char **str, t_conversion *conv, t_llint n)
{
	char	*newstr;
	size_t	len;
	size_t	newlen;

	len = ft_strlen(*str);
	if (conv->flags.minus || conv->prec_set)
		conv->flags.zero = 0;
	if (conv->flags.zero && conv->width > len)
		newlen = conv->width - get_sign_space(conv, n);
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
	if (newstr)
	{
		ft_strdel(str);
		*str = newstr;
	}
}

void	add_altform(char **str, t_conversion *conv, t_llint n)
{
	char *newstr;

	newstr = NULL;
	if (get_base(conv->type) == 8 && (*str)[0] != '0')
		newstr = ft_strjoin("0", *str);
	else if (get_base(conv->type) == 16 && n != 0)
		newstr = ft_strjoin((conv->type == 'X' ? "0X" : "0x"), *str);
	else if (get_base(conv->type) == 2 && n != 0)
		newstr = ft_strjoin("0b", *str);
	if (newstr)
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

char	*int2str_out(t_conversion *conv, t_llint n)
{
	char	*str;
	int		flag_unsigned;

	str = NULL;
	flag_unsigned = (conv->type == 'd' || conv->type == 'i') ? 0 : 1;
	if (n == 0 && conv->prec_set && conv->precision == 0)
		str = ft_strnew(0);
	else
		str = number_to_string(n, conv, flag_unsigned);	
	add_zeros(&str, conv, n);
	if (!flag_unsigned)
		add_sign(&str, conv, n);
	if (conv->flags.hash)
		add_altform(&str, conv, n);
	add_spaces(&str, conv);
	return (str);
}

char	*ptr2str_out(t_conversion *conv, t_llint n)
{
	char	*str;

	str = n ? number_to_string(n, conv, 1) : ft_strdup("(nil)");
	conv->flags.zero = n ? conv->flags.zero : 0;
	if (n)
		add_zeros(&str, conv, n);
	add_altform(&str, conv, n);
	add_spaces(&str, conv);
	return (str);
}
