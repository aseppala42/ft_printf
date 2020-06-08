#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/includes/libft.h"

# define TYPE_OPTIONS	"cspfdiouxX%"
# define FLAG_OPTIONS	"#0-+ "
# define LENGTH_OPTIONS	"hlL"
//# define ARGS		0
//# define PARAM_ARGS	1

enum	e_args
{
	ARGS,
	ORIG,
	PARAM
};

typedef		struct s_format
{
	char	type;
	int	param;
	int	width;
	int	precision;
	char	*flags;
	char	*length;
}		t_format;

int	ft_printf(const char *restrict format, ...);
char	*sprint(char *format, va_list args[3]);
char	*conversion_specifier(char *format, va_list args[3]);
char	parse_type(char *type);
int	parse_param(char *specs);
char	*parse_flags(char *specs);
int	parse_width(char *specs, va_list args);
int	parse_precision(char *specs, va_list args);
char	*parse_length(char *specs);
char	*conversion(t_format *specs, va_list args);
char	*type_int(t_format *specs, va_list args);
void	*type_float(t_format *specs, va_list args);
char	*type_uint(t_format *specs, va_list args);
char	*type_ptr(t_format *specs, uintmax_t ptr);
char	*type_str(t_format *specs, char *str);
char	*fmt_num(t_format *specs, char *str, char *prefix);
char	*add_padding(t_format *specs, char *str, char *prefix);
char	*add_prefix(char *str, char *prefix);
int	init_specs(t_format **specs, char *format, va_list args);
void	del_specs(t_format **specs);

#endif
