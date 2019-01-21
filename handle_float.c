/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:26:37 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/21 18:16:41 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

long int		ten_power(int p)
{
	long int res;
	int i;

	res = 1;
	i = -1;
	while (++i < p)
		res *= 10;
	return (res);
}

void	round_digit(int *n, int next)
{
	if (next >= 5)
		*n = *n + 1;
}

void	left2str(long double n, int size, char *str)
{
	long int	in;
	int			i;

	in = (long int)n;
	
	i = 0;
	if (n < 0)
		str[i++] = '-';
	i = size;
	while (in)
	{
		str[i] = (in % 10) + '0';
		in = in / 10;
		i++;
	}
}

void	right2str(long double n, int size, char *str)
{

}

char	*double2str(long double n, int prec)
{
	t_uint	digits;
	char	*str;
	int		i;

	digits = count_digits((t_uint)n, 10);
	str = ft_strnew((n < 0 ? 1 : 0) + digits + 1 + prec);
	left2str(n, digits, str);
	right2str(n, prec + 1, str);
}


/*
-21.324
0123456


*/

void	handle_float(va_list ap, t_conversion *conv)
{
	long double	n;
	char		*str;

	if (conv->precision == 0 && conv->prec_set == 0)
		conv->precision = 6;
	if (conv->length == L_LB)
		n = (long double)va_arg(ap, long double);
	else
		n = (double)va_arg(ap, double);
	str = dtoi(n);
	printf("%s", str);
}
