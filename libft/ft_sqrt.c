/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:00:24 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/15 17:18:17 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**double	ft_sqrt(double x)
**{
**	double	sqrt;
**	double	n;
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

double	ft_sqrt(double x)
{
	double	sqrt;
	double	n;

	n = x / 2;
	if (ft_fequal(x, 0) || ft_fequal(x, 1))
		return (x);
	while (!ft_fequal((sqrt = (x / n + n) / 2), n))
		n = sqrt;
	return (sqrt);
}
