#include "ft_printf.h"

char	*conversion(t_format *specs, va_list args)
{
	if (specs->type == 'd' || specs->type == 'i')
		return (type_int(specs, args));
	if (specs->type == 'o' || specs->type == 'u' ||
		specs->type == 'x' || specs->type == 'X')
		return (type_uint(specs, args));
	if (specs->type == 'f')
		return (type_float(specs, args));
	if (specs->type == 'c')
		return (type_str(specs, ft_chrjoin((char)va_arg(args, unsigned int), 0)));
	if (specs->type == 's')
		return (type_str(specs, va_arg(args, char *)));
	if (specs->type == 'p')
		return (type_ptr(specs, (uintmax_t)va_arg(args, unsigned long)));
	if (specs->type == '%')
		return (type_str(specs, ft_strdup("%")));
	return (0);
}
