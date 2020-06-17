/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:37:03 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/17 18:15:20 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		next_arg(va_list args[3], int param)
{
	if (!param)
		return ;
	va_end(args[PARAM]);
	va_copy(args[PARAM], args[ORIG]);
	while (--param)
		va_arg(args[PARAM], void *);
}

static char		*conversion_specifier(char *format, va_list args[3])
{
	char		*tmp;
	t_format	*specs;

	if (!format || *format == 0 || *(format + 1) == 0)
		return (0);
	format++;
	tmp = ft_strndup(format, ft_strcspn(format, TYPE_OPTIONS) + 1);
	new_specs(&specs);
	if (init_specs(&specs, tmp, args[ARGS]))
	{
		ft_strdel(&tmp);
		next_arg(args, specs->param);
		tmp = conversion(specs, specs->param ? args[PARAM] : args[ARGS]);
		format = ft_strpbrk(format, TYPE_OPTIONS) + 1;
	}
	else
		ft_strdel(&tmp);
	del_specs(&specs);
	return (format ? ft_joindel(tmp, sprint(format, args)) : tmp);
}

static char		*sprint(char *format, va_list args[3])
{
	if (!format || *format == 0)
		return (0);
	return (ft_joindel(ft_strndup(format, ft_strclen(format, '%')),
		conversion_specifier(ft_strchr(format, '%'), args)));
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		args[3];
	char		*str;
	int			len;

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
