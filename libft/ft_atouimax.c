/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atouimax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:02:04 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/17 18:34:02 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uintmax_t	ft_recursive_atouimax(const char *str, char **endptr, \
				int base, char *digits, int res)
{
	if (endptr)
		*endptr = (char *)str;
	if (!ft_strchr(digits, ft_tolower(*str)))
		return (res);
	return (ft_recursive_atouimax(str + 1, endptr, base, digits, res * base + \
		ft_strclen(digits, ft_tolower(*str))));
}

uintmax_t			ft_atouimax(const char *str, char **endptr, int base)
{
	char			*digits;

	if (endptr)
		*endptr = (char *)str;
	if (base < MIN_BASE || base > MAX_BASE)
		return (0);
	while (ft_isspace(*str))
		str++;
	digits = ft_strndup(DIGITS, base);
	if (*str == '+')
		return (ft_recursive_atouimax(++str, endptr, base, digits, 0));
	if (ft_strchr(digits, ft_tolower(*str)))
		return (ft_recursive_atouimax(str, endptr, base, digits, 0));
	return (0);
}

/*
**uintmax_t		ft_atouimax(const char *str, char **endptr, int base)
**{
**	char		*digits;
**	int			res;
**
**	if (endptr)
**		*endptr = str;
**	if (base < MIN_BASE || base > MAX_BASE)
**		return (0);
**	digits  = ft_strndup(DIGITS, base);
**	res = 0;
**	while (ft_isspace(*str))
**		str++;
**	if (*str == '+')
**		str++;
**	while (ft_strchr(digits, ft_tolower(*str)))
**	{
**		res = res * base + ft_strclen(digits, ft_tolower(*str++));
**		if (endptr)
**			*endptr = str;
**	}
**	return (res);
**}
*/
