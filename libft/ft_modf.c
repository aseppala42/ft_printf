/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:03:05 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/15 17:22:11 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**double	ft_modf(double value, double *iptr)
**{
**	*iptr = (intmax_t)value;
**	return (ft_fmod(value, 1));
**}
*/

double	ft_modf(double value, double *iptr)
{
	*iptr = (intmax_t)value;
	return (value - *iptr);
}
