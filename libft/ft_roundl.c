/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roundl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 12:52:53 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/15 12:52:56 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_roundl(long double x)
{
	if (ft_fabsl(x) - ft_imaxabs(x) < 0.5)
		return ((intmax_t)x);
	return (x < 0 ? ft_floorl(x) : ft_ceill(x));
}
