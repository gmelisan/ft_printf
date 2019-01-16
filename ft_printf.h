/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:56:36 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/16 23:47:04 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef unsigned char			t_uchar;
typedef unsigned int			t_uint;
typedef long long int			t_llint;
typedef unsigned long long int	t_ullint;

/*
** ll, h, l, ll, L
** order matters and means priority when ft_printf finds multiple lengths
*/

enum	e_length {L_NONE, L_HH, L_H, L_L, L_LL, L_LB};

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
	}				flags;
	t_uint			width;
	t_uint			precision;
	t_uchar			prec_set;
	enum e_length	length;
	t_uchar			type;
	char			*out;
}				t_conversion;

/*
** format:		%[flags][width][.precision][length]type
*/

int				ft_printf(const char *format, ...);
t_conversion	*get_conversion(va_list ap, const char *format, int *i);
void			get_flags(t_conversion *conv, const char *format, int *i);
void			get_width(va_list ap, t_conversion *conv,
							const char *format, int *i);
void			get_precision(va_list ap, t_conversion *conv,
								const char *format, int *i);
void			get_length(t_conversion *conv, const char *format, int *i);
void			get_type(t_conversion *conv, const char *format, int *i);
int				handle_conversion(va_list ap, t_conversion **conv);
void			handle_unknown(t_conversion *conv);
void			handle_decimal(va_list ap, t_conversion *conv);
void			handle_unsigned(va_list ap, t_conversion *conv);
void			handle_octal(va_list ap, t_conversion *conv);
void			handle_hexadecimal(va_list ap, t_conversion *conv);
void			handle_float(va_list ap, t_conversion *conv);
void			handle_char(va_list ap, t_conversion *conv);
void			handle_string(va_list ap, t_conversion *conv);
void			handle_pointer(va_list ap, t_conversion *conv);
char			*prepare_out(t_conversion *conv, int len);

#endif
