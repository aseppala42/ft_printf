/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:36:45 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/17 16:45:06 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conversion(t_format *specs, va_list args)
{
	if (specs->type == 'd' || specs->type == 'i')
		return (type_int(specs, args));
	if (specs->type == 'o' || specs->type == 'u' ||
		specs->type == 'x' || specs->type == 'X' || specs->type == 'b')
		return (type_uint(specs, args));
	if (specs->type == 'f')
		return (type_float(specs, args));
	if (specs->type == 'c')
		return (type_str(specs, \
			ft_chrjoin((char)va_arg(args, unsigned int), 0)));
	if (specs->type == 's')
		return (type_str(specs, va_arg(args, char *)));
	if (specs->type == 'p')
		return (type_ptr(specs, (uintmax_t)va_arg(args, unsigned long)));
	if (specs->type == '%')
		return (add_padding(specs, ft_strdup("%"), 0));
	return (0);
}
