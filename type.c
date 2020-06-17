/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:37:40 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/17 15:54:28 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*type_int(t_format *specs, va_list args)
{
	intmax_t	num;

	if (specs->length == 0)
		num = va_arg(args, int);
	else if (!ft_strcmp(specs->length, "hh"))
		num = (signed char)va_arg(args, int);
	else if (!ft_strcmp(specs->length, "h"))
		num = (short)va_arg(args, int);
	else if (!ft_strcmp(specs->length, "l"))
		num = va_arg(args, long);
	else if (!ft_strcmp(specs->length, "ll"))
		num = va_arg(args, long long);
	else if (!ft_strcmp(specs->length, "L"))
		num = va_arg(args, int);
	else
		return (0);
	if (num == 0 && specs->precision == 0)
		return (fmt_num(specs, ft_strdup(""), 0));
	return (fmt_num(specs, ft_imaxtoa(num, 10), num < 0 ? ft_strdup("-") : 0));
}

char	*type_uint(t_format *specs, va_list args)
{
	uintmax_t	num;

	if (specs->length == 0)
		num = va_arg(args, unsigned int);
	else if (!ft_strcmp(specs->length, "hh"))
		num = (unsigned char)va_arg(args, unsigned int);
	else if (!ft_strcmp(specs->length, "h"))
		num = (unsigned short)va_arg(args, unsigned int);
	else if (!ft_strcmp(specs->length, "l"))
		num = va_arg(args, unsigned long);
	else if (!ft_strcmp(specs->length, "ll"))
		num = va_arg(args, unsigned long long);
	else if (!ft_strcmp(specs->length, "L"))
		num = va_arg(args, unsigned int);
	else
		return (0);
	if (specs->type == 'o' && specs->precision == 0 && specs->flags \
		&& ft_strchr(specs->flags, '#'))
		specs->precision = 1;
	if (num == 0 && specs->precision == 0)
		return (fmt_num(specs, ft_strdup(""), 0));
	if (specs->type == 'o')
		return (fmt_num(specs, ft_uimaxtoa(num, 8), num && specs->flags \
			&& ft_strchr(specs->flags, '#') ? ft_strdup("0") : 0));
	if (specs->type == 'u')
		return (fmt_num(specs, ft_uimaxtoa(num, 10), 0));
	if (specs->type == 'x')
		return (fmt_num(specs, ft_uimaxtoa(num, 16), num && specs->flags \
			&& ft_strchr(specs->flags, '#') ? ft_strdup("0x") : 0));
	if (specs->type == 'X')
		return (ft_strupr(fmt_num(specs, ft_uimaxtoa(num, 16), num \
			&& specs->flags && ft_strchr(specs->flags, '#') ? \
			ft_strdup("0X") : 0)));
	return (0);
}

void	*type_float(t_format *specs, va_list args)
{
	long double	num;

	if (specs->length == 0)
		num = (long double)va_arg(args, double);
	else if (!ft_strcmp(specs->length, "hh"))
		num = (long double)va_arg(args, double);
	else if (!ft_strcmp(specs->length, "h"))
		num = (long double)va_arg(args, double);
	else if (!ft_strcmp(specs->length, "l"))
		num = (long double)va_arg(args, double);
	else if (!ft_strcmp(specs->length, "ll"))
		num = (long double)va_arg(args, double);
	else if (!ft_strcmp(specs->length, "L"))
		num = va_arg(args, long double);
	else
		return (0);
	if (specs->precision == 0)
		return (fmt_num(specs, ft_imaxtoa((intmax_t)num, 10), \
			num < 0 ? ft_strdup("-") : 0));
	return (fmt_num(specs, ft_ftoa(num, specs->precision), \
		num < 0 ? ft_strdup("-") : 0));
}

char	*type_ptr(t_format *specs, uintmax_t ptr)
{
	if (ptr == 0 && specs->precision == 0)
		return (fmt_num(specs, ft_strdup(""), ft_strdup("0x")));
	return (fmt_num(specs, ft_uimaxtoa(ptr, 16), ft_strdup("0x")));
}

char	*type_str(t_format *specs, char *str)
{
	str = !str ? ft_strdup("(null)") : ft_strdup(str);
	if (specs->type == 'c' && *str == 0 && specs->width)
		specs->width--;
	if (specs->precision >= 0)
		ft_memset(str + specs->precision, 0, 1);
	return (add_padding(specs, str, 0));
}
