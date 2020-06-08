#include "ft_printf.h"

void	next_arg(va_list args[3], int param)
{
	if (!param)
		return ;
	va_end(args[PARAM]);
	va_copy(args[PARAM], args[ORIG]);
	while (--param)
		va_arg(args[PARAM], void *);
}

char	*conversion_specifier(char *format, va_list args[3])
{
	char		*tmp;
	t_format	*specs;

	if (!format || *format == 0)
		return (0);
	format++;
	tmp = ft_strndup(format, ft_strcspn(format, TYPE_OPTIONS) + 1);
	if (init_specs(&specs, tmp, args[ARGS]))
	{
		next_arg(args,specs->param);
		tmp = conversion(specs, specs->param ? args[PARAM] : args[ARGS]);
		format = ft_strpbrk(format, TYPE_OPTIONS);
	}
	else
		tmp = 0;
	del_specs(&specs);
	return (format ? ft_joindel(tmp, sprint(++format, args)) : tmp);
}

char	*sprint(char *format, va_list args[3])
{
	if (!format || *format == 0)
		return (0);
	return (ft_joindel(ft_strndup(format, ft_strclen(format, '%')),
		conversion_specifier(ft_strchr(format, '%'), args)));
}

int	ft_printf(const char *restrict format, ...)
{
	va_list	args[3];
	char	*str;
	int	len;

	if (!format || *format == 0)
		return (0);
	va_start(args[ARGS], format);
	va_copy(args[ORIG], args[ARGS]);
	va_copy(args[PARAM], args[ARGS]);
	str = sprint((char *)format, args);
	va_end(args[ARGS]);
	va_end(args[ORIG]);
	va_end(args[PARAM]);
	ft_putstr(str);
	len = !str ? 0 : ft_strlen(str);
	ft_strdel(&str);
	return (len);
}
