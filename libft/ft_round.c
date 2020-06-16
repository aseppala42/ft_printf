/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 12:52:38 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/15 17:04:08 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_round(double x)
{
	if (ft_fabs(x) - ft_imaxabs(x) < 0.5)
		return ((intmax_t)x);
	return (x < 0 ? ft_floor(x) : ft_ceil(x));
}
