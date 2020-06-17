/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoimax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:06:46 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/17 18:33:29 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static intmax_t	ft_recursive_atoimax(const char *str, char **endptr, int base, \
			char *digits, int res)
{
	if (endptr)
		*endptr = (char *)str;
	if (!ft_strchr(digits, ft_tolower(*str)))
		return (res);
	return (ft_recursive_atoimax(str + 1, endptr, base, digits, res * base + \
		ft_strclen(digits, ft_tolower(*str))));
}

intmax_t		ft_atoimax(const char *str, char **endptr, int base)
{
	char		*digits;

	if (endptr)
		*endptr = (char *)str;
	if (base < MIN_BASE || base > MAX_BASE)
		return (0);
	while (ft_isspace(*str))
		str++;
	digits = ft_strndup(DIGITS, base);
	if (*str == '-')
		return (-ft_recursive_atoimax(++str, endptr, base, digits, 0));
	if (*str == '+')
		return (ft_recursive_atoimax(++str, endptr, base, digits, 0));
	if (ft_strchr(digits, ft_tolower(*str)))
		return (ft_recursive_atoimax(str, endptr, base, digits, 0));
	return (0);
}

/*
**intmax_t		ft_atoimax(const char *str, char **endptr, int base)
**{
**	char		*digits;
**	int			res;
**	int			sign;
**
**	if (endptr)
**		*endptr = str;
**	if (base < MIN_BASE || base > MAX_BASE)
**		return (0);
**	digits  = ft_strndup(DIGITS, base);
**	res = 0;
**	sign = 0;
**	while (ft_isspace(*str))
**		str++;
**	if (*str == '+')
**		str++;
**	else if (*str == '-')
**	{
**		str++;
**		sign = 1;
**	}
**	while (ft_strchr(digits, ft_tolower(*str)))
**	{
**		res = res * base + ft_strclen(digits, ft_tolower(*str++));
**		if (endptr)
**			*endptr = str;
**	}
**	return (sign ? -res : res);
**}
*/
