/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmodl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 12:54:30 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/15 17:21:20 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_fmodl(long double x, long double y)
{
	int	sign;

	if (!y)
		return (0);
	sign = x < 0 ? -1 : 1;
	x = ft_fabsl(x);
	y = ft_fabsl(y);
	while (x > y)
		x -= y;
	return (x * sign);
}
