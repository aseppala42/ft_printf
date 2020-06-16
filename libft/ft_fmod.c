/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 12:53:32 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/15 15:37:31 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_fmod(double x, double y)
{
	int	sign;

	if (!y)
		return (0);
	sign = x < 0 ? -1 : 1;
	x = ft_fabs(x);
	y = ft_fabs(y);
	while (x > y)
		x -= y;
	return (x * sign);
}
