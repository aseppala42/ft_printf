/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:36:54 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/17 19:26:32 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*add_padding(t_format *specs, char *str, char *prefix)
{
	int		len;

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

char		*fmt_unum(t_format *specs, uintmax_t num)
{
	if (specs->type == 'o' && specs->precision == 0 && specs->flags \
		&& ft_strchr(specs->flags, '#'))
		specs->precision = 1;
	if (num == 0 && specs->precision == 0)
		return (fmt_num(specs, ft_strdup(""), 0));
	else if (specs->type == 'o')
		return (fmt_num(specs, ft_uimaxtoa(num, 8), num && specs->flags \
			&& ft_strchr(specs->flags, '#') ? ft_strdup("0") : 0));
	else if (specs->type == 'u')
		return (fmt_num(specs, ft_uimaxtoa(num, 10), 0));
	else if (specs->type == 'x')
		return (fmt_num(specs, ft_uimaxtoa(num, 16), num && specs->flags \
			&& ft_strchr(specs->flags, '#') ? ft_strdup("0x") : 0));
	else if (specs->type == 'X')
		return (ft_strupr(fmt_num(specs, ft_uimaxtoa(num, 16), num \
			&& specs->flags && ft_strchr(specs->flags, '#') ? \
			ft_strdup("0X") : 0)));
	else if (specs->type == 'b')
		return (fmt_num(specs, ft_uimaxtoa(num, 2), 0));
	return (0);
}

char		*fmt_num(t_format *specs, char *str, char *prefix)
{
	int		len;

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
		str = ft_joindel(ft_memset(ft_strnew(len), '0', len), str);
	if (specs->type != 'f' && specs->precision >= 0 && specs->flags)
		ft_rmchr(specs->flags, '0');
	if (specs->type == 'o' && prefix && *str == '0')
		ft_strdel(&prefix);
	str = add_padding(specs, str, prefix);
	return (!prefix ? str : add_prefix(str, prefix));
}
