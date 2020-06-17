/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 13:50:52 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/17 18:29:21 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**char		*ft_itoa(int n)
**{
**	if (n == -2147483648)
**		return (ft_strdup("-2147483648"));
**	if (n < 0)
**		return (ft_joindel("-", ft_itoa(-n)));
**	if (n > 9)
**		return (ft_joindel(ft_itoa(n / 10), ft_chrjoin(n % 10 + '0', 0)));
**	return (ft_chrjoin(n % 10 + '0', 0));
**}
*/

char		*ft_itoa(int n)
{
	char	*str;
	char	*tmp;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(str = ft_strnew(ft_numlen(n))))
		return (0);
	tmp = str;
	if ((sign = (n < 0)))
		n = -n;
	*tmp++ = n % 10 + '0';
	while ((n /= 10))
		*tmp++ = n % 10 + '0';
	if (sign)
		*tmp = '-';
	return (ft_strrev(str));
}

/*
**char		*ft_recursive_itoa(char *str, int n, int i)
**{
**	if (n < 0)
**	{
**		str[0] = '-';
**		return (ft_recursive_itoa(str, -n, i));
**	}
**	str[i] = n % 10 + '0';
**	if (n > 9)
**		ft_recursive_itoa(str, n / 10, --i);
**	return (str);
**}
**
**char		*ft_itoa(int n)
**{
**	char	*str;
**	size_t	len;
**
**	if (n == -2147483648)
**		return (ft_strdup("-2147483648"));
**	len = ft_numlen(n);
**	if (!(str = ft_strnew(len)))
**		return (0);
**	return (ft_recursive_itoa(str, n, --len));
**}
**
** ***
**
**char		*ft_recursive_itoa(char *str, int n)
**{
**	if (n < 0)
**	{
**		ft_recursive_itoa(str, -n);
**		*(str + ft_strlen(str)) = '-';
**		return (str);
**	}
**	*str = n % 10 + '0';
**	if (n > 9)
**		ft_recursive_itoa(str + 1, n / 10);
**	return (str);
**}
**
**char		*ft_itoa(int n)
**{
**	char	*str;
**
**	if (n == -2147483648)
**		return (ft_strdup("-2147483648"));
**	if (!(str = ft_strnew(ft_numlen(n))))
**		return (0);
**	return (ft_strrev(ft_recursive_itoa(str, n)));
**}
*/
