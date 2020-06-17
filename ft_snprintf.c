/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 20:23:12 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/17 20:46:48 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_snprintf(char *restrict str, size_t size, \
					const char *restrict format, ...)
{
	va_list		args[3];
	char		*tmp;
	int			len;

	if (!format || *format == 0)
		return (0);
	va_start(args[ARGS], format);
	va_copy(args[ORIG], args[ARGS]);
	va_copy(args[PARAM], args[ARGS]);
	tmp = sprint((char *)format, args);
	va_end(args[ARGS]);
	va_end(args[ORIG]);
	va_end(args[PARAM]);
	ft_strlcpy(str, tmp, size);
	if (tmp)
		len = !str ? 0 : ft_strlen(str);
	else
		len = 0;
	ft_strdel(&tmp);
	return (len);
}
