/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 12:55:02 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/15 17:05:22 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**double	ft_pow(double base, int exp)
**{
**	double	res;
**
**	if (!exp)
**		return (1);
**	res = ft_pow(base, exp / 2);
**	if (!(exp % 2))
**		return (res * res);
**	return (exp > 0 ? res * res * base : (res * res) / base);
**}
*/

double	ft_pow(double base, int exp)
{
	double	res;
	int	i;

	res = 1;
	i = ft_abs(exp);
	while (i--)
		res *= base;
	return (exp > 0 ? res : 1 / res);
}
