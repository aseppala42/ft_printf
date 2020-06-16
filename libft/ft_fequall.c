/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fequall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:05:15 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/15 17:25:19 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_fequall(long double x, long double y)
{
	return (ft_fabsl(x - y) <= EPSILON * ft_fmaxl(1.0f, \
		ft_fmaxl(ft_fabsl(x), ft_fabsl(y))));
}
