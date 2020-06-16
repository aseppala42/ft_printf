/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:02:34 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/15 13:02:36 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_floor(double x)
{
	return ((intmax_t)x > x ? (intmax_t)(--x) : (intmax_t)x);
}
