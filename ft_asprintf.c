/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 20:17:00 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/17 20:35:06 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_asprintf(char **ret, const char *format, ...)
{
	va_list		args[3];

	if (!format || *format == 0)
		return (0);
	va_start(args[ARGS], format);
	va_copy(args[ORIG], args[ARGS]);
	va_copy(args[PARAM], args[ARGS]);
	*ret = sprint((char *)format, args);
	va_end(args[ARGS]);
	va_end(args[ORIG]);
	va_end(args[PARAM]);
	return (!*ret ? 0 : ft_strlen(*ret));
}
