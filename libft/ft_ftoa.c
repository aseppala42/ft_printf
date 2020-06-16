/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 12:45:29 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/15 16:52:30 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**char	*ft_ftoa(long double n, int precision)
**{
**	long double	iprt;
**	int		len;
**	char		*str;
**
**	n = ft_fabsl(ft_setprecision(ft_modfl(n, &iprt), precision));
**	str = ft_imaxtoa(n * ft_powl(10, precision), 10);
**	if ((len = precision - ft_strlen(str)) > 0)
**		str = ft_joindel(ft_memset(ft_strnew(len), '0', len), str);
**	return (ft_joindel(ft_imaxtoa(iprt, 10), ft_joindel(ft_strdup("."), str)));
**}
*/

char	*ft_ftoa(long double n, int precision)
{
	long double	iprt;
	int		len;
	char		*str;

	n = ft_fabsl(ft_roundl(ft_modfl(n, &iprt) * ft_powl(10, precision)));
	str = ft_imaxtoa(n, 10);
	if ((len = precision - ft_strlen(str)) > 0)
		str = ft_joindel(ft_memset(ft_strnew(len), '0', len), str);
	return (ft_joindel(ft_imaxtoa(iprt, 10), ft_joindel(ft_strdup("."), str)));
}
