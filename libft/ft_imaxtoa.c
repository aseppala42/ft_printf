/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imaxtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 12:54:22 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/18 18:21:43 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**char		*ft_recursive_imaxtoa(char *str, intmax_t n, int base, int i)
**{
**	if (n < 0)
**	{
**		str[0] = '-';
**		return (ft_recursive_imaxtoa(str, -n, base, i));
**	}
**	str[i] = (n % base > 9) ? n % base - 10 + 'a' : n % base + '0';
**	if (n > base - 1)
**		ft_recursive_imaxtoa(str, n / base, base, --i);
**	return (str);
**}
**
**char		*ft_imaxtoa(intmax_t n, int base)
**{
**	char	*str;
**	size_t	len;
**
**	if (n < -MAX_LL)
**		return (ft_strdup("-9223372036854775808"));
**	if ((n < 0 && base != 10) || base < MIN_BASE || base > MAX_BASE)
**		return (0);
**	len = ft_imaxlen(n, base);
**	if (!(str = ft_strnew(len)))
**		return (0);
**	return (ft_recursive_imaxtoa(str, n, base, --len));
**}
**
** ***
**
**char		*ft_recursive_imaxtoa(char *str, intmax_t n, int base, int i)
**{
**	if (n < 0)
**	{
**		ft_recursive_imaxtoa(str, -n, base);
**		*(str + ft_strlen(str)) = '-';
**		return (str);
**	}
**	*str = (n % base > 9) ? n % base - 10 + 'a' : n % base + '0';
**	if (n > base - 1)
**		ft_recursive_imaxtoa(str, n / base, base);
**	return (str);
**}
**
**char		*ft_imaxtoa(intmax_t n, int base)
**{
**	char	*str;
**
**	if (n < -MAX_LL)
**		return (ft_strdup("-9223372036854775808"));
**	if ((n < 0 && base != 10) || base < MIN_BASE || base > MAX_BASE)
**		return (0);
**	if (!(str = ft_strnew(ft_imaxlen(n, base))))
**		return (0);
**	return (ft_strrev(ft_recursive_imaxtoa(str, n, base)));
**}
*/

char			*ft_imaxtoa(intmax_t n, int base)
{
	char		*str;
	char		*tmp;
	int			sign;

	if (n < -MAX_LL)
		return (ft_strdup("-9223372036854775808"));
	if ((n < 0 && base != 10) || base < MIN_BASE || base > MAX_BASE)
		return (0);
	if (!(str = ft_strnew(ft_imaxlen(n, base))))
		return (0);
	tmp = str;
	if ((sign = (n < 0)))
		n = -n;
	*tmp++ = DIGITS[n % base];
	while ((n /= base))
		*tmp++ = DIGITS[n % base];
	if (sign)
		*tmp = '-';
	return (ft_strrev(str));
}

/*
**char		*ft_imaxtoa(intmax_t n, int base)
**{
**	if (n < -MAX_LL)
**		return (ft_strdup("-9223372036854775808"));
**	if ((n < 0 && base != 10) || base < MIN_BASE || base > MAX_BASE)
**		return (0);
**	if (n < 0)
**		return (ft_joindel("-", ft_imaxtoa(-n)));
**	if (n > base - 1)
**		return (ft_joindel(ft_imaxtoa(n / base),
**		ft_chrjoin((n % base > 9) ? n % base - 10 + 'a' : n % base + '0', 0)));
**	return (ft_chrjoin((n % base > 9) ? n % base - 10 + 'a' : \
**		n % base + '0', 0));
**}
*/
