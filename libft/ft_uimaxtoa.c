/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimaxtoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:01:55 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/18 18:21:27 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**char		*ft_recursive_uimaxtoa(char *str, uintmax_t n, int base, int i)
**{
**	str[i] = (n % base > 9) ? n % base - 10 + 'a' : n % base + '0';
**	if (n > base - 1)
**		ft_recursive_uimaxtoa(str, n / base, base, --i);
**	return (str);
**}
**
**char		*ft_uimaxtoa(uintmax_t n, int base)
**{
**	char	*str;
**	size_t	len;
**
**	if (base < MIN_BASE || base > MAX_BASE)
**		return (0);
**	len = ft_uimaxlen(n, base);
**	if (!(str = ft_strnew(len)))
**		return (0);
**	return (ft_recursive_uimaxtoa(str, n, base, --len));
**}
**
** ***
**
**char		*ft_recursive_uimaxtoa(char *str, uintmax_t n, int base, int i)
**{
**	*str = (n % base > 9) ? n % base - 10 + 'a' : n % base + '0';
**	if (n > base - 1)
**		ft_recursive_uimaxtoa(str, n / base, base);
**	return (str);
**}
**
**char		*ft_uimaxtoa(uintmax_t n, int base)
**{
**	char	*str;
**
**	if (base < MIN_BASE || base > MAX_BASE)
**		return (0);
**	if (!(str = ft_strnew(ft_uimaxlen(n, base))))
**		return (0);
**	return (ft_strrev(ft_recursive_uimaxtoa(str, n, base)));
**}
*/

char			*ft_uimaxtoa(uintmax_t n, int base)
{
	char		*str;
	char		*tmp;

	if (base < MIN_BASE || base > MAX_BASE)
		return (0);
	if (!(str = ft_strnew(ft_uimaxlen(n, base))))
		return (0);
	tmp = str;
	*tmp++ = DIGITS[n % base];
	while ((n /= base))
		*tmp++ = DIGITS[n % base];
	return (ft_strrev(str));
}

/*
**char		*ft_uimaxtoa(uintmax_t n, int base)
**{
**	if (base < MIN_BASE || base > MAX_BASE)
**		return (0);
**	if (n > base - 1)
**		return (ft_joindel(ft_uimaxtoa(n / base),
**		ft_chrjoin((n % base > 9) ? n % base - 10 + 'a' : n % base + '0', 0)));
**	return (ft_chrjoin((n % base > 9) ? n % base - 10 + 'a' : \
**		n % base + '0', 0));
**}
*/
