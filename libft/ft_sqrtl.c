/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrtl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:01:18 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/15 17:20:12 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**long double	ft_sqrtl(long double x)
**{
**	long double	sqrt;
**	long double	n;
**
**	sqrt = x / 2;
**	n = 0;
**	while (sqrt != n)
**	{
**		n = sqrt;
**		sqrt = (x / n + n) / 2;
**	}
**	return (sqrt);
**}
*/

long double	ft_sqrtl(long double x)
{
	long double	sqrt;
	long double	n;

	n = x / 2;
	if (ft_fequall(x, 0) || ft_fequall(x, 1))
		return (x);
	while (!ft_fequall((sqrt = (x / n + n) / 2), n))
		n = sqrt;
	return (sqrt);
}
