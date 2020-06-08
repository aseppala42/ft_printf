#include "ft_printf.h"

char	*type_int(t_format *specs, va_list args)
{
	intmax_t	num;

	if (specs->length == 0)
		num = (intmax_t)va_arg(args, int);
	else if (ft_strcmp(specs->length, "hh"))
		num = (intmax_t)((signed char)va_arg(args, int));
	else if (ft_strcmp(specs->length, "h"))
		num = (intmax_t)((short)va_arg(args, int));
	else if (ft_strcmp(specs->length, "l"))
		num = (intmax_t)va_arg(args, long);
	else if (ft_strcmp(specs->length, "ll"))
		num = (intmax_t)va_arg(args, long long);
	else if (ft_strcmp(specs->length, "L"))
		num = (intmax_t)va_arg(args, int);
	else
		return (0);
	return (fmt_num(specs, ft_imaxtoa(num, 10), num < 0 ? ft_strdup("-") : 0));
}

char	*type_uint(t_format *specs, va_list args)
{
	uintmax_t	num;

//	tässä vika. length va_args ei toimi
/*	if (specs->length == 0)
		num = (uintmax_t)va_arg(args, unsigned int);
	else if (ft_strcmp(specs->length, "hh"))
		num = (uintmax_t)((unsigned char)va_arg(args, unsigned int));
	else if (ft_strcmp(specs->length, "h"))
		num = (uintmax_t)((unsigned short)va_arg(args, unsigned int));
	else if (ft_strcmp(specs->length, "l"))
		num = (uintmax_t)va_arg(args, unsigned long);
	else if (ft_strcmp(specs->length, "ll"))
		num = (uintmax_t)va_arg(args, unsigned long long);
	else if (ft_strcmp(specs->length, "L"))
		num = (uintmax_t)va_arg(args, unsigned int);
	else
		return (0);*/
	num = va_arg(args, uintmax_t);
	if (specs->type == 'o')
		return (fmt_num(specs, ft_uimaxtoa(num, 8), num && specs->flags && ft_strchr(specs->flags, '#') ? ft_strdup("0") : 0));
	if (specs->type == 'u')
		return (fmt_num(specs, ft_uimaxtoa(num, 10), 0));
	if (specs->type == 'x')
		return (fmt_num(specs, ft_uimaxtoa(num, 16), num && specs->flags && ft_strchr(specs->flags, '#') ? ft_strdup("0x") : 0));
	if (specs->type == 'X')
		return (ft_strupr(fmt_num(specs, ft_uimaxtoa(num, 16), num && specs->flags && ft_strchr(specs->flags, '#') ? ft_strdup("0X") : 0)));
	return (0);
}

void	*type_float(t_format *specs, va_list args)
{
	long double	num;

	if (specs->length == 0)
		num = (long double)va_arg(args, double);
	else if (ft_strcmp(specs->length, "hh"))
		num = (long double)va_arg(args, double);
	else if (ft_strcmp(specs->length, "h"))
		num = (long double)va_arg(args, double);
	else if (ft_strcmp(specs->length, "l"))
		num = (long double)va_arg(args, double);
	else if (ft_strcmp(specs->length, "ll"))
		num = (long double)va_arg(args, double);
	else if (ft_strcmp(specs->length, "L"))
		num = va_arg(args, long double);
	else
		return (0);
	if (specs->precision == 0)
		return (fmt_num(specs, ft_imaxtoa((intmax_t)num, 10), num < 0 ? ft_strdup("-") : 0));
	return (fmt_num(specs, ft_ftoa(num, specs->precision), num < 0 ? ft_strdup("-") : 0));
}

char	*type_ptr(t_format *specs, uintmax_t ptr)
{
	return (fmt_num(specs, ft_uimaxtoa(ptr, 16), ft_strdup("0x")));
}

char	*type_str(t_format *specs, char *str)
{
//	int	len;

	str = !str ? ft_strdup("(null)") : ft_strdup(str);
	if (specs->precision)
		ft_memset(str + specs->precision, 0, 1);
/*	if ((len = specs->width - ft_strlen(str)) > 0)
	{
		if (specs->flags && ft_strchr(specs->flags, '-'))
			return (ft_joindel(str, ft_memset(ft_strnew(len), ' ', len)));
		if (specs->flags && ft_strchr(specs->flags, '0'))
			return (ft_joindel(ft_memset(ft_strnew(len), '0', len), str));
		return (ft_joindel(ft_memset(ft_strnew(len), ' ', len), str));
	}*/
	return (add_padding(specs, str, 0));
}
