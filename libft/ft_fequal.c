/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fequal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:05:08 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/15 17:25:58 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_fequal(double x, double y)
{
	return (ft_fabs(x - y) <= EPSILON * ft_fmax(1.0f, \
		ft_fmax(ft_fabs(x), ft_fabs(y))));
}
