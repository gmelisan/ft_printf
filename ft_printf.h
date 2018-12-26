/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:56:36 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/26 21:48:01 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef unsigned char	t_uchar;
typedef unsigned int	t_uint;

/*
** ll, h, l, ll, L
*/

# define L_HH	1
# define L_H	2
# define L_L	3
# define L_LL	4
# define L_LB	5

/*
** %[flags][width][.precision][length]type
*/

typedef struct	s_conversion
{
	struct
	{
		t_uint	hash	: 1;
		t_uint	zero	: 1;
		t_uint	minus	: 1;
		t_uint	space	: 1;
		t_uint	plus	: 1;
		t_uint	apos	: 1;
	}			flags;
	t_uint		width;
	t_uint		precision;
	t_uchar		length;
	t_uchar		type;
	char		*out;
	int			outlen;
}				t_conversion;

int				ft_printf(const char *format, ...);
t_conversion	*get_conversion(va_list ap, const char *format, int *i);
void			get_flags(t_conversion *conv, const char *format, int *i);
void			get_width(va_list ap, t_conversion *conv, const char *format, int *i);
void			get_precision(va_list ap, t_conversion *conv, const char *format, int *i);
void			get_length(t_conversion *conv, const char *format, int *i);
void			get_type(t_conversion *conv, const char *format, int *i);
void			handle_conversion(va_list ap, t_conversion **conv);

#endif