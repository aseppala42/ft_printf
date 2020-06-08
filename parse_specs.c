#include "ft_printf.h"

int	parse_param(char *param)
{
	if (ft_strchr(param, '$') && ft_isdigit(*param))
		return (ft_atoi(param));
	return (0);
}

char	*parse_flags(char *flags)
{
	if (ft_strchr(FLAG_OPTIONS, *flags))
		return (ft_joindel(ft_chrjoin(*flags, 0), parse_flags(flags + 1)));
	return (0);
}

int	parse_width(char *width, va_list args)
{
	if (ft_isdigit(*width))
		return (ft_atoi(width));
	else if (*width == '*')
		return (va_arg(args, int));
	return (0);
}

int	parse_precision(char *precision, va_list args)
{
	if (*precision == '.' && ft_isdigit(*(precision + 1)))
		return (ft_atoi(++precision));
	else if (*precision == '.' && *(precision + 1) == '*')
		return (va_arg(args, int));
	return (-1);
}

char	*parse_length(char *len)
{
	if (ft_strchr(LENGTH_OPTIONS, *len))
		return (ft_joindel(ft_chrjoin(*len, 0), parse_length(len + 1)));
	return (0);
}
