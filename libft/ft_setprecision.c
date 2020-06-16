/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setprecision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:03:23 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/15 17:22:42 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**long double	ft_setprecision(long double x, int precision)
**{
**	long double	iprt;
**
**	x = ft_modfl(x, &iprt);
**	x = ft_roundl(ft_powl(10, precision) * x) / ft_powl(10, precision);
**	return (iprt + x);
**}
*/

long double	ft_setprecision(long double x, int precision)
{
	return (ft_roundl(ft_powl(10, precision) * x) / ft_powl(10, precision));
}
