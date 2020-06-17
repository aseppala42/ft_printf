/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 20:17:00 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/17 20:39:30 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_sprintf(char *restrict str, const char *restrict format, ...)
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
	ft_strcpy(str, tmp);
	len = !tmp ? 0 : ft_strlen(tmp);
	ft_strdel(&tmp);
	return (len);
}
