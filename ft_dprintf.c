/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 20:36:53 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/17 20:38:31 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_dprintf(int fd, const char *restrict format, ...)
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
	ft_putstr_fd(str, fd);
	len = !str ? 0 : ft_strlen(str);
	ft_strdel(&str);
	return (len);
}
