#include "ft_printf.h"

char	parse_type(char *type)
{
	if ((type = ft_strpbrk(type, TYPE_OPTIONS)))
		return (*type);
	return (0);
}

int	init_specs(t_format **specs, char *format, va_list args)
{
	*specs = (t_format *)malloc(sizeof(t_format));
	if (!((*specs)->type = parse_type(format)))
		return (0);
	if (((*specs)->param = parse_param(format)))
		format += ft_strclen(format, '$') + 1;
	if (((*specs)->flags = parse_flags(format)))
		format += ft_strlen((*specs)->flags);
	if (((*specs)->width = parse_width(format, args)))
		while (ft_isdigit(*format) || ft_isspace(*format) || *format == '*')
			format++;
	if (((*specs)->precision = parse_precision(format, args)))
		while (ft_isdigit(*format) || ft_isspace(*format) || *format == '*')
			format++;
	if ((*specs)->precision < 0)
		(*specs)->precision = (*specs)->type == 'f' ? 6 : 0;
	if (((*specs)->length = parse_length(format)))
		format += ft_strlen((*specs)->length);
	return (1);
}

void	del_specs(t_format **specs)
{
	ft_strdel(&(*specs)->flags);
	ft_strdel(&(*specs)->length);
	free(*specs);
	*specs = 0;
}
