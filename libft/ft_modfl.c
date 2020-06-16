/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modfl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 12:52:11 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/15 17:01:52 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**long double	ft_modfl(long double value, long double *iptr)
**{
**	*iptr = (intmax_t)value;
**	return (ft_fmodl(value, 1));
**}
*/

long double	ft_modfl(long double value, long double *iptr)
{
	*iptr = (intmax_t)value;
	return (value - *iptr);
}
