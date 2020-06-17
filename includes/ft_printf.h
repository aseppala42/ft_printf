/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:37:11 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/17 16:43:42 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"

# define TYPE_OPTIONS	"cspfdiouxXb%"
# define FLAG_OPTIONS	"#0-+ "
# define LENGTH_OPTIONS	"hlLzj"

enum	e_args
{
	ARGS,
	ORIG,
	PARAM
};

typedef struct	s_format
{
	char	type;
	int	param;
	int	width;
	int	precision;
	char	*flags;
	char	*length;
}		t_format;

int		ft_printf(const char *restrict format, ...);
static char	*sprint(char *format, va_list args[3]);
static char	*conversion_specifier(char *format, va_list args[3]);
static char	parse_type(char *type);
int		parse_param(char *specs);
char		*parse_flags(char *specs);
int		parse_width(char *specs, va_list args);
int		parse_precision(char *specs, va_list args);
char		*parse_length(char *specs);
char		*conversion(t_format *specs, va_list args);
char		*type_int(t_format *specs, va_list args);
void		*type_float(t_format *specs, va_list args);
char		*type_uint(t_format *specs, va_list args);
char		*type_ptr(t_format *specs, uintmax_t ptr);
char		*type_str(t_format *specs, char *str);
char		*fmt_num(t_format *specs, char *str, char *prefix);
char		*add_padding(t_format *specs, char *str, char *prefix);
static char	*add_prefix(char *str, char *prefix);
int		init_specs(t_format **specs, char *format, va_list args);
void		del_specs(t_format **specs);
void		new_specs(t_format **specs);

#endif
