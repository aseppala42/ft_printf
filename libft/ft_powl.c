/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 12:58:51 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/17 18:26:44 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**long double	ft_powl(long double base, int exp)
**{
**	long double	res;
**
**	if (!exp)
**		return (1);
**	res = ft_powl(base, exp / 2);
**	if (!(exp % 2))
**		return (res * res);
**	return (exp > 0 ? res * res * base : (res * res) / base);
**}
*/

long double		ft_powl(long double base, int exp)
{
	long double	res;
	int			i;

	res = 1;
	i = ft_abs(exp);
	while (i--)
		res *= base;
	return (exp > 0 ? res : 1 / res);
}
