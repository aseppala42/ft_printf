/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:37:33 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/16 21:06:14 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	parse_type(char *type)
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
	if (((*specs)->width = parse_width(format, args)) < 0)
	{
		(*specs)->width *= -1;
		(*specs)->flags = ft_joindel(ft_strdup("-"), (*specs)->flags);
	}
	while (ft_isdigit(*format) || ft_isspace(*format) || *format == '*')
		format++;
	(*specs)->precision = parse_precision(format, args);
	if ((*specs)->precision < 0 && (*specs)->type == 'f')
		(*specs)->precision = 6;
	while (*format == '.' || ft_isdigit(*format) || ft_isspace(*format) \
		|| *format == '*')
		format++;
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
