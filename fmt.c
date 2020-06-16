/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:36:54 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/16 20:09:46 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_padding(t_format *specs, char *str, char *prefix)
{
	int	len;

	len = specs->width - ft_strlen(str) - (!prefix ? 0 : ft_strlen(prefix));
	if (len > 0)
	{
		if (specs->flags && ft_strchr(specs->flags, '-'))
			str = ft_joindel(str, ft_memset(ft_strnew(len), ' ', len));
		else if (specs->flags && ft_strchr(specs->flags, '0'))
			str = ft_joindel(ft_memset(ft_strnew(len), '0', len), str);
		else
			str = ft_joindel(ft_memset(ft_strnew(len), ' ', len), str);
	}
	return (str);
}

static char	*add_prefix(char *str, char *prefix)
{
	char	*tmp;

	if (*str != ' ')
		return (ft_joindel(prefix, str));
	tmp = ft_joindel(prefix, ft_strdup(ft_strpbrk(str, DIGITS)));
	ft_memset(ft_strpbrk(str, DIGITS), 0, 1);
	return (ft_joindel(str, tmp));
}

char	*fmt_num(t_format *specs, char *str, char *prefix)
{
	int	len;

	if (*str == '-')
		ft_strlcpy(str, str + 1, ft_strlen(str));
	else if ((specs->type == 'd' || specs->type == 'i' || specs->type == 'f') \
		&& specs->flags && ft_strchr(specs->flags, '+'))
		prefix = ft_strdup("+");
	else if ((specs->type == 'd' || specs->type == 'i' || specs->type == 'f') \
		&& !prefix && specs->flags && ft_strchr(specs->flags, ' '))
		prefix = ft_strdup(" ");
	if (specs->type != 'f' && specs->precision >= 0 \
		&& (len = specs->precision - ft_strlen(str)) > 0)
	{
		str = ft_joindel(ft_memset(ft_strnew(len), '0', len), str);
		if (specs->flags)
			ft_rmchr(specs->flags, '0');
	}
	str = add_padding(specs, str, prefix);
	return (!prefix ? str : add_prefix(str, prefix));
}
