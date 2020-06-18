/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imaxlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <aseppala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:19:08 by aseppala          #+#    #+#             */
/*   Updated: 2020/06/18 18:19:25 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_imaxlen(intmax_t n, int base)
{
	if ((n < 0 && base != 10) || base < MIN_BASE || base > MAX_BASE)
		return (0);
	if (n < 0)
		return (1 + ft_imaxlen(-n, base));
	if (n > base - 1)
		return (1 + ft_imaxlen(n / base, base));
	return (1);
}
